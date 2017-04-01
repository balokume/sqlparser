#include "Schema.h"
#include "dbms.h"
#include <sstream>
#include <iterator>
using namespace std;

namespace dbms{
Schema::Schema()
{
    loadFromFile();
}

Schema::~Schema(){
    for(auto it = tables.cbegin(); it != tables.cend();){
        if(it->second->temporary){
            it->second->removeFile();
            it = tables.erase(it);
        }else{
            it++;
        }
    }

    saveToFile();

    for(auto ele : tables)
        delete ele.second;
}

// split a string with delimiter
inline std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }

    return elems;
}

void Schema::loadFromFile(){
    ifstream is(CATALOG_FILE);
    string line;
    while(getline(is, line)){
        // tablename
        string name = line.substr(10);
        Table* tbl = new Table(name);

        // columns
        getline(is, line);
        map<string, Column*> columns;
        string strCol = line.substr(8);
        vector<string> tokens = split(strCol, ',');
        for(auto col_str:tokens){

            Column* col = new Column();
            col->fromString(col_str);
            columns.insert(make_pair(col->name, col));
        }

        tbl->setColumns(columns);

        // primary key
        getline(is, line);
        string key = line.substr(12);
        if(key != "NULL"){
            tbl->setPrimaryKey(key);
        }

        // record size
        getline(is, line);
        // total size
        getline(is, line);
        // records
        getline(is, line);
        string records = line.substr(8);
        tbl->setRecords(stoi(records));

        tables.insert(make_pair(name, tbl));
    }

    is.close();
}

void Schema::saveToFile(){
    ofstream os(CATALOG_FILE);
    for(auto t : tables){
        Table* tbl = t.second;
        os<<"tablename="<<tbl->getName()<<endl;
        os<<"columns=";
        string str;
        for(auto it : tbl->getColumns()){
           str += it.second->toString() + ",";
        }
        os<<str.substr(0, str.size()-1)<<endl;
        os<<"primary key=";
        if(tbl->getPrimaryKey() != NULL)
            os<<tbl->getPrimaryKey()->name<<endl;
        else
            os<<"NULL"<<endl;
        os<<"recordsize="<<tbl->getRecordSize()<<endl;
        os<<"totalsize="<<tbl->getTotalSize()<<endl;
        os<<"records="<<tbl->getRecords()<<endl;
    }

    os.close();
}

void Schema::executeStatement(const hsql::SQLStatement *stmt){
    switch (stmt->type()) {
    case hsql::kStmtCreate:
        executeCreate((const hsql::CreateStatement*)stmt);
        break;
    case hsql::kStmtSelect:
        executeSelect((const hsql::SelectStatement*)stmt);
        break;
    case hsql::kStmtInsert:
        executeInsert((const hsql::InsertStatement*)stmt);
        break;
    case hsql::kStmtShow:
        executeShow((const hsql::ShowStatement*)stmt);
        break;
    case hsql::kStmtDrop:
        executeDrop((const hsql::DropStatement*)stmt);
        break;
    default:
        break;
    }
}

void Schema::executeCreate(const hsql::CreateStatement *stmt){
    auto it = tables.find(stmt->tableName);
    if(it != tables.end()){
        DBMS::log()<<"Table "<<stmt->tableName<<" already exists"<<endl;
        return;
    }

    Table* tbl = new Table(stmt->tableName);
    if(tbl->createFile()){
        map<string, Column*> columns;
        for (hsql::ColumnDefinition* col_def : *stmt->columns) {
            Column::DataType type;
            int size;

            if(col_def->type == hsql::ColumnDefinition::DataType::INT){
                type = Column::INT;
                size = INT_SIZE;
            }
            else if(col_def->type == hsql::ColumnDefinition::DataType::TEXT){
                type = Column::CHAR;
                size = col_def->size;
            }else{
                DBMS::log()<<"Invalid column type."<<endl;
                return;
            }
            Column* col = new Column(col_def->name, type, size);
            columns.insert(make_pair(col->name, col));
        }

        tbl->setColumns(columns);
        if(stmt->primaryKey != NULL)
            tbl->setPrimaryKey(stmt->primaryKey->name);

        tables.insert(pair<string, Table*>(stmt->tableName, tbl));

        DBMS::log()<<"Create table "<<stmt->tableName<<" success"<<endl;
    }
    else{
        delete tbl;
        DBMS::log()<<"Create table "<<stmt->tableName<<" fail"<<endl;
    }
}

void Schema::executeInsert(const hsql::InsertStatement *stmt){
    auto it = tables.find(stmt->tableName);
    if(it == tables.end()){
        DBMS::log()<<"Table "<<stmt->tableName<<" does not exist"<<endl;
    }else{
        if(it->second->insert(stmt))
            DBMS::log()<<"Insert success"<<endl;
    }
}

void Schema::executeSelect(const hsql::SelectStatement *stmt){
    if(stmt->fromTable->type == hsql::kTableName){
        auto it = tables.find(stmt->fromTable->name);
        if(it == tables.end()){
            DBMS::log()<<"Table "<<stmt->fromTable->name<<" does not exist"<<endl;
        }else{
            it->second->select(stmt);
        }
    }else if(stmt->fromTable->type == hsql::kTableSelect){
        if(createRefTable(stmt->fromTable)){
            auto it = tables.find(stmt->fromTable->alias);
            it->second->select(stmt);
        }
    }
}

bool Schema::createRefTable(hsql::TableRef *ref){
    string tmpTableName = ref->alias;
    string fromTableName = ref->select->fromTable->getName();

    if(ref->select->fromTable->type == hsql::kTableSelect){
        if(!createRefTable(ref->select->fromTable))
            return false;
    }else{
    }

    auto it = tables.find(tmpTableName);
    if(it != tables.end()){
        DBMS::log()<<"Table "<<tmpTableName<<" already exists"<<endl;
        return false;
    }

    auto fromTbl = tables.find(fromTableName);
    if(fromTbl == tables.end()){
        DBMS::log()<<"Table "<<fromTableName<<" does not exist"<<endl;
        return false;
    }

    Table* tmpTbl = new Table(tmpTableName);
    tmpTbl->temporary = true;
    if(tmpTbl->createFile()){
        map<string, Column*> columns;
        if(ref->select->selectList->size() == 1 && (*ref->select->selectList)[0]->type == hsql::kExprStar){    // select *
            for(auto col : fromTbl->second->getColumns()){
                columns.insert(make_pair(col.first, col.second->clone()));
            }
        }else{
            for (hsql::Expr* expr : *(ref->select->selectList)) {
                auto col = fromTbl->second->getColumns().find(expr->name);
                if(col == fromTbl->second->getColumns().end()){
                    DBMS::log()<<"Column '"<<expr->name<<"' does not exist"<<endl;
                    delete tmpTbl;
                    return false;
                }

                columns.insert(make_pair(col->first, col->second->clone()));
            }
        }

        tmpTbl->setColumns(columns);


        if(fromTbl->second->select(ref->select, tmpTbl))
            tables.insert(pair<string, Table*>(tmpTableName, tmpTbl));
        else{
            delete tmpTbl;
            return false;
        }
    }
    else{
        delete tmpTbl;
        return false;
    }

    return true;
}

void Schema::executeShow(const hsql::ShowStatement *stmt){

}

void Schema::executeDrop(const hsql::DropStatement *stmt){

}

}
