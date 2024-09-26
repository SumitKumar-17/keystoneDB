#ifndef STMT_H
#define STMT_H
#include <string>

namespace skDB {
    enum SQLStmtType {
        skSQL_SELECT,
        skSQL_INSERT,
        skSQL_UPDATE,
        skSQL_CREATE,
        skSQL_DELETE,
        skSQL_DROP,
        skSQL_USE,
        skSQL_SHOW,
        skSQL_EXIT,
    };

    class SQLStmt {
    public:
        explicit SQLStmt(SQLStmtType type);

        SQLStmtType type() const;

        virtual std::string toString();

        virtual ~SQLStmt();

    private:
        SQLStmtType type_;
    };

    class ExitStmt : public SQLStmt {
    public:
        ExitStmt();
    };
}


#endif //STMT_H
