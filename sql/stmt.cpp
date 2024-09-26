#include "sql/stmt.h"

namespace skDB {
    SQLStmt::SQLStmt(const SQLStmtType type) : type_(type) {
    }

    SQLStmtType SQLStmt::type() const {
        return type_;
    }

    std::string SQLStmt::toString() {
        return "Default string";
    }

    SQLStmt::~SQLStmt() = default;

    ExitStmt::ExitStmt(): SQLStmt(skSQL_EXIT) {
    }
}
