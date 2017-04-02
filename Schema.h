#ifndef SCHEMA_H
#define SCHEMA_H

#include "Table.h"

namespace dbms{
class Schema
{
public:
    Schema();
    ~Schema();

    void saveToFile();

    void executeStatement(hsql::SQLStatement* stmt);
private:
    void loadFromFile();

    void executeCreate(hsql::CreateStatement* stmt);
    void executeInsert(hsql::InsertStatement* stmt);
    void executeSelect(hsql::SelectStatement* stmt);
    void executeShow(hsql::ShowStatement* stmt);
    void executeDrop(hsql::DropStatement* stmt);

    bool createRefTable( hsql::TableRef* ref);

    std::map<std::string, Table*> tables;
};
}
#endif // SCHEMA_H
