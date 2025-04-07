#include "sql/parser_result.h"

namespace keystoneDB {
    void ParserResult::addStatement(SQLStmt *stmt) {
        statements.push_back(stmt);
    }

    std::vector<SQLStmt *> *ParserResult::getStatements() {
        return &statements;
    }
}
