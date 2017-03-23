#ifndef TABLEUTIL_H
#define TABLEUTIL_H

#include <fstream>
#include "Table.h"
#include "sql/statements.h"

namespace dbms{
class TableUtil
{
public:
    TableUtil();

    static char* readColBytes(std::ifstream& os, Column* col);
    static void printColValue(std::ifstream& os, Column* col);

    static Condition checkWhere(hsql::Expr* whereClause, const std::map<std::string, Column*>& columns);
    static bool isColumnExist(const hsql::Expr* expr, const std::map<std::string, Column*>& columns);
    static bool checkColValueWithCondition(std::ifstream& os, int offset, std::vector<Column*> cols, hsql::Expr* whereClause);
};
}
#endif // TABLEUTIL_H
