#include "sql/drop_stmt.h"
#include "sql/stmt.h"

namespace keystoneDB {
    DropStmt::DropStmt(const DropType type, const TableName name_): SQLStmt(skSQL_DROP), type(type) {
        name = name_;
    }
}
