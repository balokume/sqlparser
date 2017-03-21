#include "dbms.h"
#include <iostream>
#include "SQLParser.h"
#include "sqlhelper.h"

namespace dbms{

ostream* DBMS::os;

DBMS::DBMS() : mode(RUN_MODE::INTERACTIVE)
{
}

DBMS::~DBMS(){
    if(mode == RUN_MODE::SCRIPT){
        ((ofstream*)os)->close();
        delete os;
    }

    delete schema;
}

void DBMS::setMode(RUN_MODE mode){
    this->mode = mode;

    if(mode == RUN_MODE::SCRIPT){
        os = new ofstream("output.txt");
//        os = &std::cout;
    }else{
        os = &std::cout;
    }

    schema = new Schema();
}

bool DBMS::processQuery(const string &query){
    // parse a given query
    hsql::SQLParserResult* result = hsql::SQLParser::parseSQLString(query);

    // check whether the parsing was successful
    if (result->isValid()) {
//        printf("Parsed successfully!\n");
//        printf("Number of statements: %lu\n", result->size());

        for (unsigned i = 0; i < result->size(); ++i) {
            if(result->getStatement(i)->type() == hsql::StatementType::kStmtQuit){
                delete result;
                return true;
            }
            else{
//                exec->executeStatement(result->getStatement(i));
                schema->executeStatement(result->getStatement(i));
            }

            // Print a statement summary.
//            hsql::printStatementInfo(result->getStatement(i));
        }

        delete result;
        return false;
    } else {
        fprintf(stderr, "Given string is not a valid SQL query.\n");
        fprintf(stderr, "%s (L%d:%d)\n",
                result->errorMsg(),
                result->errorLine(),
                result->errorColumn());
        delete result;
        return false;
    }

}
}
