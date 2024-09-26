#ifndef USE_STMT_H
#define USE_STMT_H
#include "stmt.h"
#include "table.h"

namespace skDB {
    class UseStmt final : public SQLStmt {
    public:
        explicit UseStmt(TableName name_);
        ~UseStmt() override;

        TableName name{};
    };
}
#endif //USE_STMT_H
