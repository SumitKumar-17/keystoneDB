#include "sql/stmt.h"

namespace skDB {
    SQLStmt::SQLStmt(const SQLStmtType type) : type_(type) {
    }
    SQLStmtType SQLStmt::type() const {
        return type_;
    }
    SQLStmt::~SQLStmt() = default;
}