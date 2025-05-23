#include "sql/show_stmt.h"

namespace keystoneDB {
    ShowStmt::ShowStmt(const ShowType show_type_): SQLStmt(skSQL_SHOW), show_type(show_type_) {
    }

    ShowType ShowStmt::getShowType() const {
        return show_type;
    }

    ShowStmt::~ShowStmt() = default;
}
