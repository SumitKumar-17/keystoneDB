#include "sql/use_stmt.h"
#include "sql/table.h"

namespace skDB {
    UseStmt::UseStmt(const TableName name_): SQLStmt(skDB_SQL_USE), name(name_) {}
    UseStmt::~UseStmt() = default;
}