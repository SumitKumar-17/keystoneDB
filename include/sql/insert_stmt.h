#ifndef INSERT_STMT_H
#define INSERT_STMT_H
#include "stmt.h"
#include "table.h"
#include <vector>

namespace keystoneDB {
    class Parameter;

    class InsertStmt final : public SQLStmt {
    public:
        InsertStmt(TableName table_name_, std::vector<ColumnName *> *optColumnName,
                   std::vector<std::vector<Parameter *> *> *params);

        ~InsertStmt() override;

        TableName table_name;

        std::vector<ColumnName *> *opt_column_names;

        std::vector<std::vector<Parameter *> *> *parameters;
    };


    class Parameter {
    public:
        explicit Parameter(double d_);

        explicit Parameter(int x_);

        explicit Parameter(char *str_);

        explicit Parameter();

        [[nodiscard]] double getDouble() const;

        [[nodiscard]] int getInt() const;

        [[nodiscard]] char *getChar() const;

        [[nodiscard]] DataType getType() const;

        virtual ~Parameter();

    private:
        char *str;
        int x;
        double d;
        DataType type;
    };
}
#endif //INSERT_STMT_H
