#include <iostream>
#include <stdlib.h>
#include <string>

// include the sql parser
#include "SQLParser.h"

// contains printing utilities
#include "sqlhelper.h"
#include <cassert>
using namespace std;

int main(int argc, char *argv[])
{
//    cout << "Hello World!" << endl;
////#line 1 "src.txt"
//#line 1 "testhead.h"
////    assert(1+1==3);
//    return 0;

    if (argc <= 1) {
        fprintf(stderr, "Usage: ./example \"SELECT * FROM test;\"\n");
        return -1;
    }
    std::string query = argv[1];

    // parse a given query
    hsql::SQLParserResult* result = hsql::SQLParser::parseSQLString(query);

    // check whether the parsing was successful
    if (result->isValid()) {
        printf("Parsed successfully!\n");
        printf("Number of statements: %lu\n", result->size());

        for (unsigned i = 0; i < result->size(); ++i) {
            // Print a statement summary.
            hsql::printStatementInfo(result->getStatement(i));
        }

        delete result;
        return 0;
    } else {
        fprintf(stderr, "Given string is not a valid SQL query.\n");
        fprintf(stderr, "%s (L%d:%d)\n",
                result->errorMsg(),
                result->errorLine(),
                result->errorColumn());
        delete result;
        return -1;
    }
}
