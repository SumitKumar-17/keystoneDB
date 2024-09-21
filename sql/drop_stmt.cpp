#include "sql/drop_stmt.h"
#include "sql/stmt.h"

namespace skDB {
    DropStmt::DropStmt(const DropType type, const TableName name_): SQLStmt(skDB_SQL_DROP), type(type) {
        name = name_;
    }
}