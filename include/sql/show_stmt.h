#ifndef SHOW_STMT_H
#define SHOW_STMT_H
#include "stmt.h"

namespace skDB {
    enum ShowType {
        ShowDatabases,
        ShowTables
    };

    class ShowStmt final:public SQLStmt {
        public:
            explicit ShowStmt(ShowType shoe_type_);
            ~ShowStmt() override;

        private:
            ShowType show_type;
    };
}

#endif //SHOW_STMT_H