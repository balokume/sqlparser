#ifndef TABLE_H
#define TABLE_H
#include <map>
#include <string>
#include "defines.h"
#include "sql/statements.h"

namespace dbms {

struct Column{

    enum DataType {
        INT = 1,
        CHAR = 2,
    };

    Column(const std::string& name, DataType type, int size);
    Column();

    std::string toString();
    void fromString(const std::string& str);

    std::string name;
    int size;
    int trueSize;
    DataType type;
    int offset = 0;
    Column* clone();
};

class Table
{
public:
    Table();
    Table(const std::string& name);
    virtual ~Table();

    Column* getColumn(const std::string& colName);
    void setColumns(const std::map<std::string, Column*>& value);
    void setPrimaryKey(const std::string& colName);
    bool createFile();
    bool removeFile();
    bool insert(const hsql::InsertStatement *stmt);
    bool select(const hsql::SelectStatement *stmt, Table* dstTable = NULL, hsql::InsertStatement* insertStmt = NULL);

    std::string getName(){return name;}
    std::string getFileName(){return filename;}
    const Column* getPrimaryKey(){return primaryKey;}
    int getRecords(){return records;}
    int getRecordSize(){return recordSize;}
    int getTotalSize(){return records*recordSize;}
    const std::map<std::string, Column*>& getColumns(){return columns;}
    void setRecords(int count){records = count;}

    bool temporary = false;
private:

    std::string name;
    std::map<std::string, Column*> columns;
    std::string filename;
    Column* primaryKey = NULL;

    int records = 0;
    int recordSize = 0;
    int trueRecordSize = 0;

};

enum Condition{
    NONE = 0,
    NORMAL = 1,
    INVALID = 2,
    NO_DATA = 3,
};

}

#endif // TABLE_H
