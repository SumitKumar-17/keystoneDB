#ifndef DROP_STMT_H
#define DROP_STMT_H
#include "stmt.h"

namespace skDB {
    enum DropType{
        DropTable,
        DropDatabase,
    };

    class DropStmt : SQLStmt {
        public: 
            explicit DropStmt(DropType type);

            char *name{};
            DropType type;
        
        private:
    };
}

#endif //DROP_STMT_H