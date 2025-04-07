#include "sql/select_stmt.h"
#include <vector>

#include "sql/table.h"
#include "sql/exp.h"

namespace keystoneDB {
    SelectStmt::SelectStmt(std::vector<ColumnName *> *column_names_, std::vector<TableName> *table_names_,
                           Exp *whereExp_): SQLStmt(skSQL_SELECT), column_names(column_names_),
                                            table_names(table_names_), whereExp(whereExp_) {
    }
}
