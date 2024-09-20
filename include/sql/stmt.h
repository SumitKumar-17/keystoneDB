#ifndef STMT_H
#define STMT_H

namespace skDB{
    class SQLStmt{};

    enum SQLStmtType{
        SQL_SELECT,
        SQL_INSERT,
        SQL_UPDATE,
        SQL_DELETE,
        SQL_CREATE,
        SQL_DROP,
        SQL_USE,
        SQL_SHOW,
    };
    
}

#endif // STMT_H