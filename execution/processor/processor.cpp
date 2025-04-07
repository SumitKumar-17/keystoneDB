#include <utility>

#include "sql/exp.h"
#include "execution/executor.h"

namespace keystoneDB {
    AbstractExpProcessor::AbstractExpProcessor(ExecutionContext context): context_(std::move(context)) {
    }

    bool AbstractExpProcessor::process(ScalarExp *scalar_exp) {
        return true;
    }

    bool AbstractExpProcessor::process(BetweenExpr *between_expr) {
        return true;
    }

    bool AbstractExpProcessor::process(BinaryExp *binary_exp) {
        return true;
    }

    bool AbstractExpProcessor::process(UnaryExp *unary_exp) {
        return true;
    }
}
