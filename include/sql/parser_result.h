#ifndef PARSER_RESULT_H
#define PARSER_RESULT_H
#include <vector>

#include "stmt.h"

namespace skDB{
    class ParserResult{
        public:
            ParserResult()=default;

            void addStatement(SQLStmt *stmt);

        private:
            std::vector<SQLStmt *> statements;
    };
}

#endif //PARSER_RESULT_H