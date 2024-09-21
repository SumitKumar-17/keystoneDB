#include "execution/executor.h"

namespace skDB {
    void Executor::executeUpdateStmt(const UpdateStmt *update_stmt) const {
        assert(update_stmt!=nullptr);
        std::string cur, tablename;
        if (!checkTable(update_stmt->table_name, cur, tablename)) {
            return;
        }
        std::vector<TempRow> rows;
        collectTableAllRows(rows, cur, tablename);
    }
}