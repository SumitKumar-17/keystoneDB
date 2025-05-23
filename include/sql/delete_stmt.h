#ifndef DELETE_STMT_H
#define DELETE_STMT_H
#include "exp.h"
#include "stmt.h"

namespace keystoneDB {
    class DeleteStmt final : public SQLStmt {
    public:
        DeleteStmt(TableName table_name_, Exp *whereExp_);
        ~DeleteStmt() override;

        TableName table_name;
        Exp *whereExp;
    };
}
#endif //DELETE_STMT_H
