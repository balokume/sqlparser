#include "Table.h"
#include <fstream>
#include "dbms.h"
#include <cstring>
#include <iomanip>
#include "TableUtil.h"

using namespace std;

namespace dbms {

Column::Column(const std::string &name, DataType type, int size)
    :name(name), type(type), size(size){
    if(type == CHAR)
        trueSize = size + 1;
    else
        trueSize = size;
}

Column::Column(){}

string Column::toString(){
    string str = name;
    if(type == INT)
        str += ":INT";
    else if(type == CHAR)
        str += ":CHAR(" + to_string(size) + ")";
    return str;
}

void Column::fromString(const string &str){
    int idx = str.find(":");
    name = str.substr(0, idx);
    string tmp = str.substr(idx+1);
    if(tmp == "INT"){
        type = INT;
        size = INT_SIZE;
        trueSize = size;
    }
    else if(tmp.substr(0, 4) == "CHAR"){
        type = CHAR;
        idx = tmp.find(")");
        tmp  = tmp.substr(5, idx-5);
        size = stoi(tmp);
        trueSize = size + 1;
    }
}

Column* Column::clone(){
    Column* col = new Column(name, type, size);
    col->tableName = tableName;
    col->offset = offset;
    col->trueSize = trueSize;

    return col;
}

bool Column::compareName(hsql::Expr *expr){
    if(!expr->hasTable() && expr->name == name)
        return true;
    else if(expr->hasTable() && expr->table == tableName && expr->name == name)
        return true;
    else
        return false;
}

Table::Table()
{

}
Table::~Table(){
    for(auto col : columns){
        delete col;
    }
}

Table::Table(const std::string &name):name(name){
    filename = TABLE_DIR + name + ".tbl";
}

Column* Table::getColumn(const std::string& colName){
    return TableUtil::getColumn(columns, colName);
}

Column* Table::getColumn(   hsql::Expr *expr){
    return TableUtil::getColumn(columns, expr);
}

void Table::setColumns(const vector<Column *> &value, bool changeTableName){
    columns = value;
    recordSize = 0;
    trueRecordSize = 0;
    for(auto ele : columns){
        ele->offset = trueRecordSize;
        if(changeTableName)
            ele->tableName = name;

        recordSize += ele->size;
        trueRecordSize += ele->trueSize;
    }
}

void Table::setPrimaryKey(const string &colName){
    primaryKey = getColumn(colName);
}

bool Table::createFile(){
    ofstream os(filename, ios::out | ios::binary);
    return os.is_open();
}

bool Table::removeFile(){
    return remove(filename.c_str());
}

bool Table::insert(hsql::InsertStatement *stmt){
    // open table file
    ofstream os(filename, ios::out|ios::binary|ios::app);
    if(!os.is_open()){
        DBMS::log()<<"Can't open database "<<name<<endl;
        return false;
    }

    // insert by values
    if(stmt->type == hsql::InsertStatement::kInsertValues){
        // check size of column and value in statements
        if(stmt->columns != NULL && stmt->columns->size() != stmt->values->size()){
            DBMS::log()<<"Column count doesn't match value count"<<endl;
            return false;
        }
        if(stmt->columns == NULL && columns.size() < stmt->values->size()){
            DBMS::log()<<"INSERT has more expressions than target columns"<<endl;
            return false;
        }

        //  check unknown column in statement
        if(stmt->columns != NULL){
            for(char* col_name : *stmt->columns){
                auto it = getColumn(col_name);
                if(it == NULL){
                    DBMS::log()<<"Unknown column "<<col_name<<" in 'field list'"<<endl;
                    return false;
                }
            }
        }

        char* row = new char[trueRecordSize];
        char* ptr = row;
        int idx = 0;
        for(auto col : columns){
            hsql::Expr* expr = NULL;
            // find corresponding value in statement
            if(stmt->columns != NULL){
                for(int i = 0; i < stmt->columns->size(); i++){
                    if(col->name == (*stmt->columns)[i]){
                        expr = (*stmt->values)[i];
                        break;
                    }
                }

            }else{
                if(idx < stmt->values->size())
                    expr = (*stmt->values)[idx];
                else
                    expr = NULL;
            }

            if(expr != NULL){
                if(col->type == Column::DataType::CHAR){
                    if(expr->type == hsql::kExprLiteralString){
                        // check size
                        if(strlen(expr->name) > col->size){
                            DBMS::log()<<"Data too long for column '"<<col->name<<"'"<<endl;
                            delete row;
                            return false;
                        }
                        memcpy(ptr, expr->name, strlen(expr->name)+1);
                        ptr += col->trueSize;
                    }else if(expr->type == hsql::kExprLiteralInt){
                        const char* str = to_string(expr->ival).c_str();
                        // check size
                        if(strlen(str) > col->size){
                            DBMS::log()<<"Data too long for column '"<<col->name<<"'"<<endl;
                            delete row;
                            return false;
                        }
                        memcpy(ptr, str, strlen(str)+1);
                        ptr += col->trueSize;
                    }else{
                        DBMS::log()<<"Unexpeced data type"<<endl;
                        delete row;
                        return false;
                    }
                }else{
                    // check type consistency
                    if(expr->type == hsql::kExprLiteralString){
                        DBMS::log()<<"Invalid integer value: '"<<expr->name<<"' for column '"<<col->name<<"'"<<endl;
                        delete row;
                        return false;
                    }else if(expr->type == hsql::kExprLiteralInt){
                        memcpy(ptr, &expr->ival, INT_SIZE);
                        ptr += col->trueSize;
                    }else{
                        DBMS::log()<<"Unexpeced data type"<<endl;
                        delete row;
                        return false;
                    }


                }
            }else{  // not specified in statement, assign NULL
                if(col->type == Column::DataType::CHAR){
                    ptr[0] = '\0';
                    ptr += col->trueSize;
                }else{
                    memset(ptr, 0, col->trueSize);
                    ptr += col->trueSize;
                }
            }

            idx++;
        }

        os.write(row, trueRecordSize);
        delete row;
        records++;
    }else{  // insert by selection
    }
    os.close();
    return true;
}



bool Table::select(hsql::SelectStatement *stmt, Table* dstTable, hsql::InsertStatement* insertStmt){
    ifstream os(filename, ios::in|ios::binary);

    if(!os.is_open()){
        DBMS::log()<<"Can't open database "<<name<<endl;
        return false;
    }

    // assemble queried columns vector
    vector<pair<string, Column*>> cols;
    if(stmt->selectList->size() == 1 && (*stmt->selectList)[0]->type == hsql::kExprStar){    // select *
        for(auto col : columns)
            cols.push_back(make_pair(col->name, col));
    }else{
        for(hsql::Expr* expr : *stmt->selectList){

            if(expr->type == hsql::kExprLiteralString || expr->type == hsql::kExprColumnRef){   // select C1,C2,...
                string colName = expr->name;
                if(expr->hasTable())
                    colName = string(expr->table) + "." + colName;
                Column* col = getColumn(expr);

                if(col == NULL){
                    DBMS::log()<<"Column '"<<colName<<"' does not exist"<<endl;
                    return false;
                }else{
                    cols.push_back(make_pair(col->name, col));
                }
            }else if(expr->type == hsql::kExprLiteralInt){
                cols.push_back(make_pair(to_string(expr->ival), (Column*)NULL));
            }
        }
    }

    // check where clause
    Condition condition = Condition::NONE;
    if(stmt->whereClause != NULL)
        condition = TableUtil::checkWhere(stmt->whereClause, columns);

    if(condition == Condition::INVALID)
        return false;

    // print header
    if(dstTable == NULL){
        for(auto it : cols){
            Column* col = it.second;
            if(col == NULL || col->type == Column::INT )
                DBMS::log()<<left<<setw(8)<<setfill(' ')<<it.first;
            else if(col->type == Column::CHAR)
                DBMS::log()<<left<<setw(col->size+2 > 8 ? col->size+2 : 8)<<setfill(' ')<<it.first;
        }
        DBMS::log()<<endl;
    }

    if(condition == Condition::NO_DATA)
        return false;

    // assemble condition columns vector
    vector<Column*> conCols;
    if(condition == Condition::NORMAL){
        Column* con = getColumn(stmt->whereClause->expr);
        conCols.push_back(con);
        if(stmt->whereClause->expr2->type == hsql::kExprColumnRef){
            con = getColumn(stmt->whereClause->expr2->name);
            conCols.push_back(con);
        }
    }

    bool hasInsertStatement = insertStmt != NULL;
    // print records
    for(int i = 0; i < records; i++){
        // check condition
        if(condition == Condition::NORMAL){
            if(!TableUtil::checkColValueWithCondition(os, i*trueRecordSize, conCols, stmt->whereClause))
                continue;
        }

        if(dstTable == NULL){
            for(auto it:cols){
                Column* col = it.second;
                if(col != NULL){
                    os.seekg(i*trueRecordSize + col->offset);
                    TableUtil::printColValue(os, col);
                }
                else{
                    DBMS::log()<<left<<setw(8)<<setfill(' ')<<it.first;
                }
            }
            DBMS::log()<<endl;
        }else{
            if(!hasInsertStatement){
                insertStmt = new hsql::InsertStatement(hsql::InsertStatement::kInsertValues);
                insertStmt->tableName = strdup(dstTable->getName().c_str());
                insertStmt->columns = new vector<char*>;
            }

            insertStmt->values = new vector<hsql::Expr*>;

            for(auto itFromCol:cols){
                Column* fromCol = itFromCol.second;
                if(fromCol != NULL){
                    if(!hasInsertStatement)
                        insertStmt->columns->push_back(strdup(fromCol->name.c_str()));
                    os.seekg(i*trueRecordSize + fromCol->offset);
                    if(fromCol->type == Column::CHAR){

                        char *bytes = new char[fromCol->trueSize];
                        os.read(bytes, fromCol->trueSize);

                        hsql::Expr* expr = new hsql::Expr(hsql::kExprLiteralString);
                        expr->name = bytes;
                        insertStmt->values->push_back(expr);
                    }else if(fromCol->type == Column::INT){

                        char *bytes = new char[fromCol->trueSize];
                        os.read(bytes, fromCol->trueSize);
                        hsql::Expr* expr = new hsql::Expr(hsql::kExprLiteralInt);\
                        expr->ival = *reinterpret_cast<int*>(bytes);
                        insertStmt->values->push_back(expr);
                        delete bytes;
                    }
                }
                else{
                    hsql::Expr* expr = new hsql::Expr(hsql::kExprLiteralInt);\
                    expr->ival = stoi(itFromCol.first);
                    insertStmt->values->push_back(expr);
                }
            }

            bool insertSuccess = dstTable->insert(insertStmt);
            if(hasInsertStatement){
                delete insertStmt->values;
                insertStmt->values = NULL;
            }
            else
                delete insertStmt;

            if(!insertSuccess)  return false;
        }
    }
    return true;
}

bool Table::join(Column *leftCol, Table *rightTable, Column *rightCol, Table *dstTable){
    ifstream leftFile(filename, ios::in|ios::binary);
    if(!leftFile.is_open()){
        DBMS::log()<<"Can't open database "<<name<<endl;
        return false;
    }

    ifstream rightFile(rightTable->getFileName(), ios::in|ios::binary);
    if(!rightFile.is_open()){
        DBMS::log()<<"Can't open database "<<rightTable->getName()<<endl;
        return false;
    }

    ofstream dstFile(dstTable->getFileName(), ios::out|ios::binary|ios::app);
    if(!dstFile.is_open()){
        DBMS::log()<<"Can't open database "<<dstTable->getName()<<endl;
        return false;
    }

    // loop left file on column
    char* leftBuffer = new char[leftCol->trueSize];
    char* rightBuffer = new char[rightCol->trueSize];
    char* leftRecordBuffer = new char[trueRecordSize];
    char* rightRecordBuffer = new char[rightTable->getTrueRecordSize()];
    for(int leftIdx = 0; leftIdx < records; leftIdx++){
        leftFile.seekg(leftIdx * trueRecordSize);
        leftFile.read(leftRecordBuffer, trueRecordSize);

        leftFile.seekg(leftIdx * trueRecordSize + leftCol->offset);
        leftFile.read(leftBuffer, leftCol->trueSize);

        for(int rightIdx = 0; rightIdx < rightTable->getRecords(); rightIdx++){
            rightFile.seekg(rightIdx * rightTable->getTrueRecordSize() + rightCol->offset);
            rightFile.read(rightBuffer, rightCol->trueSize);

            // compare value
            if(leftCol->type == Column::INT && *(int*)leftBuffer == *(int*)rightBuffer ||
                    leftCol->type == Column::CHAR && strcmp(leftBuffer, rightBuffer) == 0){
                rightFile.seekg(rightIdx * rightTable->getTrueRecordSize());
                rightFile.read(rightRecordBuffer, rightTable->getTrueRecordSize());

                dstFile.write(leftRecordBuffer, trueRecordSize);
                dstFile.write(rightRecordBuffer, rightTable->getTrueRecordSize());

                dstTable->increaseRecords();
            }
        }
    }

    delete leftBuffer, rightBuffer, leftRecordBuffer, rightRecordBuffer;
    return true;
}
}
