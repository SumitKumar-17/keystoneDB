#ifndef EXECUTOR_H
#define EXECUTOR_H
#include <rocksdb/db.h>
#include "sql/create_stmt.h"
#include "sql/parser_result.h"

namespace skDB {
    class Executor {
        public:
            Executor();
            bool execute(ParserResult *result);
            bool dispatch(SQLStmt *stmt);
            void shutdown() const;
            void executeCreateStmt(CreateStmt *create_stmt);
            bool init();
        private:
            std::string currentDB;
            rocksdb::DB *db;
    };

    class ExecutionResult {
        public:
            bool ok();
    };
}

#endif //EXECUTOR_H