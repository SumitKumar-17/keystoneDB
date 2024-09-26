#include "sql/exp.h"
#include "execution/executor.h"

namespace skDB{
    ExpProcessor::ExpProcessor(ExecutionContext context): context_(context){}

    bool ExpProcessor::process(BetweenExpr *between_expr){}
};
