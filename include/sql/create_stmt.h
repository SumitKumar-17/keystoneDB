#ifndef CREATE_STMT_H
#define CREATE_STMT_H
#include "stmt.h"

namespace skDB{
    enum CreateStmtType{
        DATABASE,
        TABLE
    };

    class CreateStmt final : public SQLStmt {
        ~CreateStmt() override;
    };
}

#endif // CREATE_STMT_H