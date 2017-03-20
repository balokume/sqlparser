#ifndef DBMS_H
#define DBMS_H
#include <fstream>

using namespace std;
namespace dbms {

enum RUN_MODE{
    INTERACTIVE = 1
};

class DBMS
{
public:
    DBMS();
    ~DBMS();

    void setMode(RUN_MODE mode);
    bool processQuery(const string& query);

private:
    RUN_MODE mode;
    ostream* os;
};

}

#endif // DBMS_H
