#include "sql/use_stmt.h"
#include "sql/table.h"

namespace keystoneDB {
    UseStmt::UseStmt(const TableName name_): SQLStmt(skSQL_USE), name(name_) {
    }

    UseStmt::~UseStmt() = default;
}
