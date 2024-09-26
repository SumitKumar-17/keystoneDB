#include "sql/create_stmt.h"

#include "sql/table.h"
#include <cassert>

namespace skDB {
    // may be ambiguous for TableName here.
    CreateStmt::CreateStmt(TableName name_) : SQLStmt(skSQL_CREATE), name(name_),createType(CreateDatabase), list(nullptr) {
        assert(name.schema!=nullptr&& name.name==nullptr);
    }

    CreateStmt::CreateStmt(TableName name_, std::vector<DataDefinition *> *list_) : SQLStmt(skSQL_CREATE),
        name(name_), createType(CreateTable),
        list(list_) {
        assert(name.name!=nullptr);
    }

    CreateStmt::~CreateStmt() = default;
}
