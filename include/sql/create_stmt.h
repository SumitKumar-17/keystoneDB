#ifndef CREATE_STMT_H
#define CREATE_STMT_H
#include "stmt.h"

namespace skDB{
    enum CreateStmtType{
        DATABASE,
        TABLE
    };

    class CreateStmt : public SQLStmt{
    };
}

#endif // CREATE_STMT_H