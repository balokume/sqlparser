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
    DataType type;
};

class Table
{
public:
    Table();
    Table(const std::string& name);
    virtual ~Table();

    void setColumns(const std::map<std::string, Column*>& value);
    void setPrimaryKey(const std::string& colName);
    bool createFile();
    bool insert(const hsql::InsertStatement *stmt);
    bool select(const hsql::SelectStatement *stmt);

    std::string getName(){return name;};
    const Column* getPrimaryKey(){return primaryKey;};
    int getRecords(){return records;};
    int getRecordSize(){return rawRecordSize;};
    int getTotalSize(){return records*rawRecordSize;};
    const std::map<std::string, Column*>& getColumns(){return columns;};
    void setRecords(int count){records = count;};

private:

    std::string name;
    std::map<std::string, Column*> columns;
    std::string filename;
    Column* primaryKey = NULL;

    int records = 0;
    int recordSize = 0;
    int rawRecordSize = 0;
};

}

#endif // TABLE_H
