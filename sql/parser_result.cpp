#include "sql/parser_result.h"
namespace skDB {
    void ParserResult::addStatement(SQLStmt *stmt) {
        statements.push_back(stmt);
    }
}