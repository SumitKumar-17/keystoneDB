#ifndef UPDATE_STMT_H
#define UPDATE_STMT_H
#include "exp.h"
#include "stmt.h"
#include "table.h"
#include <vector>

namespace keystoneDB {
    class UpdateAssign {
    public:
        UpdateAssign(ColumnName *column_name_, Exp *right_);

        ColumnName *column_name;

        Exp *right;
    };

    class UpdateStmt : public SQLStmt {
    public:
        UpdateStmt(TableName table_name_, std::vector<UpdateAssign *> *list_, Exp *whereExp_);

        ~UpdateStmt() override;

        TableName table_name;
        std::vector<UpdateAssign *> *update_assigns;
        Exp *whereExp;
    };
}
#endif //UPDATE_STMT_H
