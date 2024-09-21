#ifndef STMT_H
#define STMT_H
#include <string>

namespace skDB{
    enum SQLStmtType{
        skDB_SQL_SELECT,
        skDB_SQL_INSERT,
        skDB_SQL_UPDATE,
        skDB_SQL_DELETE,
        skDB_SQL_CREATE,
        skDB_SQL_DROP,
        skDB_SQL_USE,
        skDB_SQL_SHOW,
        skDB_SQL_EXIT,
    };

    class SQLStmt{
        public: 
            explicit SQLStmt(SQLStmtType type);

            SQLStmtType type() const;

            virtual std::string toString();

            virtual ~SQLStmt();
        
        private:
            SQLStmtType type_;
    };

    class ExitStmt:public SQLStmt{
        public:
            ExitStmt();
    };
    
}

#endif // STMT_H