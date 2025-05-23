#ifndef SHOW_STMT_H
#define SHOW_STMT_H
#include "stmt.h"

namespace keystoneDB {
    enum ShowType {
        ShowDatabases,
        ShowTables,
    };

    class ShowStmt final : public SQLStmt {
    public:
        explicit ShowStmt(ShowType show_type_);

        ~ShowStmt() override;

        ShowType getShowType() const;

    private:
        ShowType show_type;
    };
}
#endif //SHOW_STMT_H
