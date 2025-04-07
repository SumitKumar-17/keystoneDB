#include "sql/delete_stmt.h"

namespace keystoneDB {
    DeleteStmt::~DeleteStmt() = default;

    DeleteStmt::DeleteStmt(TableName table_name_, Exp *whereExp_) : SQLStmt(skSQL_DELETE), table_name(table_name_),whereExp(whereExp_) {
    }
}
