#include "sql/table.h"
namespace skDB{
    DataDefinition::DataDefinition(DataType type_): type(type_), data_name(nullptr) {}
    DataDefinition::~DataDefinition() = default;

    void DataDefinition::setName(char *data_name){
        this->data_name=data_name;
    }

    CharDefinition::~CharDefinition()=default;
    CharDefinition::CharDefinition(DataType type_, int len_): DataDefinition(type_), len(len_) {}

    int CharDefinition::getLen() const {
        return len;
    }
}