#include "execution/executor.h"
#include <iostream>
#include "sql/parser_result.h"

namespace skDB {
    Executor::Executor() = default;


    bool Executor::execute(ParserResult *results) {
        for (auto &result: *results->getStatements()) {
            if (!dispatch(result)) {
                return false;
            }
        }
        return true;
    }

    bool Executor::dispatch(SQLStmt *stmt) {
        switch (stmt->type()) {
            case skDB_SQL_USE:
                executeUseStmt(dynamic_cast<UseStmt *>(stmt));
                break;
            case skDB_SQL_DROP:
                break;
            case skDB_SQL_SHOW:
                executeShowStmt(dynamic_cast<ShowStmt *>(stmt));
                break;
            case skDB_SQL_DELETE:
                break;
            case skDB_SQL_INSERT:
                executeInsertStmt(dynamic_cast<InsertStmt *>(stmt));
                break;
            case skDB_SQL_CREATE:
                executeCreateStmt(dynamic_cast<CreateStmt *>(stmt));
                break;
            case skDB_SQL_EXIT:
                return false;
            case skDB_SQL_SELECT:
                break;
            default:
                std::cout << "Unknown SQL statement type" << std::endl;
                break;
        }
        return true;
    }

    void Executor::shutdown() const {
        rocksdb::WaitForCompactOptions opt = rocksdb::WaitForCompactOptions();
        opt.close_db = true;
        auto s = db->WaitForCompact(opt);
        assert(s.ok());
        delete db;
    }

    bool ExecutionResult::ok() {
        return true;
    }

    bool Executor::init() {
        rocksdb::Options options;
        options.create_if_missing = true;
        rocksdb::Status status = rocksdb::DB::Open(options, "/tmp/testdb", &db);
        assert(status.ok());
        return true;
        // if (status.ok()) status = db->Put(rocksdb::WriteOptions(), "1", "1");
        // std::string value;
        // if (status.ok()) status = db->Get(rocksdb::ReadOptions(), "2", &value);
        // std::cout << status.ok();
        // assert(status.ok());

        // status = db->Delete(rocksdb::WriteOptions(), "1");
        // assert(status.ok());
    }
}