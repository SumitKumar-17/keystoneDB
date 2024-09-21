#include "sql/show_stmt.h"

namespace skDB{
    ShowStmt::ShowStmt(const ShowType show_type_):SQLStmt(skDB_SQL_SHOW), show_type(show_type_) {}
    ShowStmt::~ShowStmt() = default;
}