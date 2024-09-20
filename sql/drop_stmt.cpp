#include "sql/drop_stmt.h"
#include "sql/stmt.h"

namespace skDB {
    DropStmt::DropStmt(const DropType type): SQLStmt(skSQL_DROP), type(type) {
    }
}