#include "sql/stmt.h"

namespace skDB {
    SQLStmt::SQLStmt(const SQLStmtType type) : type_(type) {}

    SQLStmtType SQLStmt::type() const {
        return type_;
    }

    std::string SQLStmt::toString() {
        return "Default String";
    }

    SQLStmt::~SQLStmt() = default;

    ExitStmt::ExitStmt() : SQLStmt(skDB_SQL_EXIT) {}
}