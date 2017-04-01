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

    void executeStatement(const hsql::SQLStatement* stmt);
private:
    void loadFromFile();

    void executeCreate(const hsql::CreateStatement* stmt);
    void executeInsert(const hsql::InsertStatement* stmt);
    void executeSelect(const hsql::SelectStatement* stmt);
    void executeShow(const hsql::ShowStatement* stmt);
    void executeDrop(const hsql::DropStatement* stmt);

    bool createRefTable( hsql::TableRef* ref);

    std::map<std::string, Table*> tables;
};
}
#endif // SCHEMA_H
