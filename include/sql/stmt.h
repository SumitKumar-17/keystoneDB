#ifndef STMT_H
#define STMT_H

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
    };

    class SQLStmt{
        public: 
            explicit SQLStmt(SQLStmtType type);

            SQLStmtType type() const;

            virtual ~SQLStmt();
        
        private:
            SQLStmtType type_;
    };
    
}

#endif // STMT_H