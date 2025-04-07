#include "sql/table.h"

#include <cassert>

namespace keystoneDB {
    DataDefinition::DataDefinition(DataType type_): type(type_), data_name(nullptr), constraints(nullptr) {
    }


    DataDefinition::~DataDefinition() = default;


    void DataDefinition::setName(char *data_name) {
        this->data_name = data_name;
    }

    void DataDefinition::setColumnConstraints(std::vector<ColumnConstraintType> *constraints) {
        assert(this->constraints==nullptr);
        this->constraints = constraints;
    }

    CharDefinition::~CharDefinition() = default;

    CharDefinition::CharDefinition(DataType type_, int len_): DataDefinition(type_), len(len_) {
    }

    int CharDefinition::getLen() const {
        return len;
    }
}
