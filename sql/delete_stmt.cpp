#include "sql/delete_stmt.h"

namespace skDB {
    DeleteStmt::~DeleteStmt() = default;
    DeleteStmt::DeleteStmt(TableName table_name_, Exp *whereExp_) : SQLStmt(skDB_SQL_DELETE), table_name(table_name_),
                                                                    whereExp(whereExp_) {
    }
}