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
    }
    else if(tmp.substr(0, 4) == "CHAR"){
        type = CHAR;
        idx = tmp.find(")");
        tmp  = tmp.substr(5, idx-5);
        size = stoi(tmp);
    }
}

Table::Table()
{

}
Table::~Table(){
    for(auto col : columns){
        delete col.second;
    }
}

Table::Table(const std::string &name):name(name){
    filename = TABLE_DIR + name + ".tbl";
}

void Table::setColumns(const std::map<string, Column *> &value){
    columns = value;
    recordSize = 0;
    rawRecordSize = 0;
    for(auto ele : columns){
        ele.second->offset = recordSize;
        if(ele.second->type == Column::DataType::INT)
            recordSize += ele.second->size;
        else
            recordSize += ele.second->size + 1;

        rawRecordSize += ele.second->size;
    }
}

void Table::setPrimaryKey(const string &colName){
    primaryKey = columns[colName];
}

bool Table::createFile(){
    ofstream os(filename, ios::out | ios::binary);
    if(!os.is_open()){
        DBMS::log()<<"Create table "<<name<<" fail"<<endl;
        return false;
    }else{
        DBMS::log()<<"Create table "<<name<<" success"<<endl;
        os.close();
        return true;
    }
}

bool Table::insert(const hsql::InsertStatement *stmt){
    // open table file
    ofstream os(filename, ios::out|ios::binary|ios::app);
    if(!os.is_open()){
        DBMS::log()<<"Can't open database "<<name<<endl;
        os.close();
        return false;
    }

    // insert by values
    if(stmt->type == hsql::InsertStatement::kInsertValues){
        // check size of column and value in statements
        if(stmt->columns != NULL && stmt->columns->size() != stmt->values->size() ||
           stmt->columns == NULL && columns.size() != stmt->values->size() ){
            DBMS::log()<<"Column count doesn't match value count"<<endl;
            os.close();
            return false;
        }

        //  check unknown column in statement
        if(stmt->columns != NULL){
            for(char* col_name : *stmt->columns){
                auto it = columns.find(col_name);
                if(it == columns.end()){
                    DBMS::log()<<"Unknown column "<<col_name<<" in 'field list'"<<endl;
                    os.close();
                    return false;
                }
            }
        }

        char* row = new char[recordSize];
        char* ptr = row;
        int idx = 0;
        for(auto it : columns){
            Column* col = it.second;
            hsql::Expr* expr = NULL;
            // find corresponding value in statement
            if(stmt->columns != NULL){
                for(int i = 0; i < stmt->columns->size(); i++){
                    if(it.first == (*stmt->columns)[i]){
                        expr = (*stmt->values)[i];
                        break;
                    }
                }

            }else{
                expr = (*stmt->values)[idx];
            }

            if(expr != NULL){
                if(col->type == Column::DataType::CHAR){
                    if(expr->type == hsql::kExprLiteralString){
                        // check size
                        if(strlen(expr->name) > col->size){
                            DBMS::log()<<"Data too long for column '"<<col->name<<"'"<<endl;
                            os.close();
                            delete row;
                            return false;
                        }
                        memcpy(ptr, expr->name, strlen(expr->name)+1);
                        ptr += col->size+1;
                    }else if(expr->type == hsql::kExprLiteralInt){
                        const char* str = to_string(expr->ival).c_str();
                        // check size
                        if(strlen(str) > col->size){
                            DBMS::log()<<"Data too long for column '"<<col->name<<"'"<<endl;
                            os.close();
                            delete row;
                            return false;
                        }
                        memcpy(ptr, str, strlen(str)+1);
                        ptr += col->size+1;
                    }else{
                        DBMS::log()<<"Unexpeced data type"<<endl;
                        os.close();
                        delete row;
                        return false;
                    }
                }else{
                    // check type consistency
                    if(col->type == Column::DataType::CHAR){
                        DBMS::log()<<"Invalid integer value: '"<<expr->name<<"' for column '"<<col->name<<"'"<<endl;
                        os.close();
                        delete row;
                        return false;
                    }else if(expr->type == hsql::kExprLiteralInt){
                        memcpy(ptr, &expr->ival, INT_SIZE);
                        ptr += col->size;
                    }else{
                        DBMS::log()<<"Unexpeced data type"<<endl;
                        os.close();
                        delete row;
                        return false;
                    }


                }
            }else{  // not specified in statement, assign NULL
                if(col->type == Column::DataType::CHAR){
                    ptr[0] = '\0';
                    ptr += col->size+1;
                }else{
                    memset(ptr, 0, col->size);
                    ptr += col->size;
                }
            }

            idx++;
        }

        os.write(row, recordSize);
        delete row;
        records++;
    }else{  // insert by selection

    }

    DBMS::log()<<"Insert success"<<endl;
    os.close();
    return true;
}



bool Table::select(const hsql::SelectStatement *stmt){
    ifstream os(filename, ios::in|ios::binary);
    if(!os.is_open()){
        DBMS::log()<<"Can't open database "<<name<<endl;
        return false;
    }

    // assemble queried columns vector
    vector<pair<string, Column*>> cols;
    if(stmt->selectList->size() == 1 && (*stmt->selectList)[0]->type == hsql::kExprStar){    // select *
        for(auto it : columns)
            cols.push_back(it);
    }else{
        for(hsql::Expr* expr : *stmt->selectList){

            if(expr->type == hsql::kExprLiteralString || expr->type == hsql::kExprColumnRef){   // select C1,C2,...
                auto it = columns.find(expr->name);

                if(it == columns.end()){
                    DBMS::log()<<"Column '"<<expr->name<<"' does not exist"<<endl;
                    return false;
                }else{
                    cols.push_back(*it);
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
    for(auto it : cols){
        Column* col = it.second;
        if(col == NULL || col->type == Column::INT )
            DBMS::log()<<left<<setw(8)<<setfill(' ')<<it.first;
        else if(col->type == Column::CHAR)
            DBMS::log()<<left<<setw(col->size)<<setfill(' ')<<it.first;
    }
    DBMS::log()<<endl;

    if(condition == Condition::NO_DATA)
        return false;

    // assemble condition columns vector
    vector<Column*> conCols;
    if(condition == Condition::NORMAL){
        auto con = columns.find(stmt->whereClause->expr->name);
        conCols.push_back(con->second);
        if(stmt->whereClause->expr2->type == hsql::kExprColumnRef){
            con = columns.find(stmt->whereClause->expr2->name);
            conCols.push_back(con->second);
        }
    }

    // print records
    for(int i = 0; i < records; i++){
        // check condition
        if(condition == Condition::NORMAL){
            if(!TableUtil::checkColValueWithCondition(os, i*recordSize, conCols, stmt->whereClause))
                continue;
        }


        for(auto it:cols){
            Column* col = it.second;
            if(col != NULL){
                os.seekg(i*recordSize + col->offset);
                TableUtil::printColValue(os, col);
            }
            else{
                DBMS::log()<<left<<setw(8)<<setfill(' ')<<it.first;
            }
        }
        DBMS::log()<<endl;
    }

    return true;
}
}
