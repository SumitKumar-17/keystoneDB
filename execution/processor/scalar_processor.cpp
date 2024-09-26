#include <iostream>
#include <ostream>
#include "sql/exp.h"
#include "execution/executor.h"

namespace skDB {
    bool ExpProcessor::process(ScalarExp *scalar_exp) {
        switch (scalar_exp->scalarType()) {
            case ScalarChar:
                break;
            case ScalarInteger:
                break;
            case ScalarName:
                break;
            case ScalarNULL:
                break;
            default:
                std::cout << "Unsupported scalor" << std::endl;
                return false;
        }
    }
}
