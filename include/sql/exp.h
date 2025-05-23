#ifndef EXP_H
#define EXP_H
#include <string>
#include <utility>
#include "table.h"

namespace keystoneDB {
    // forward declaration
    class AbstractExpProcessor;

    struct ColumnFullName {
        std::string table_name, db_name, column_name;

        ColumnFullName(std::string db_name, std::string table_name,
                       std::string column_name);

        ColumnFullName() = default;

        [[nodiscard]] std::string toString() const;

        bool operator==(const ColumnFullName &full_name) const {
            return full_name.toString() == this->toString();
        }
    };

    struct ColumnFullNameHasher {
        size_t operator()(const ColumnFullName &full_name) const {
            return std::hash<std::string>()(full_name.toString());
        }
    };

    enum ScalarType {
        ScalarChar,
        ScalarName,
        ScalarFloat,
        ScalarNULL,
        ScalarInteger,
        ScalarInvalid,
    };

    enum UnaryExpType {
        UnaryNegate,
        UnaryIsNull,
        UnaryIsNotNull,
        UnaryNot,
    };

    enum BinaryExpType {
        BinaryAdd,
        BinaryMul,
        BinaryDiv,
        BinarySub,
        BinaryModulo,
        BinaryXOR,
        BinaryEquals,
        BinaryNotEquals,
        BinaryGreatEQ,
        BinaryLessEQ,
        BinaryGreat,
        BinaryLess,
        BinaryAND,
        BinaryOR,
    };


    enum ExpType {
        ExpBinary,
        ExpUnary,
        ExpBetween,
        ExpScalar,
    };

    class Value {
    public:
        Value(); // Invalid

        explicit Value(int x); // integer
        explicit Value(std::string s);

        static Value MakeNullValue();

        [[nodiscard]] ScalarType getType() const;

        [[nodiscard]] std::string getChar() const;

        [[nodiscard]] int getInteger() const;

        bool ok() const;

    private:
        ScalarType type_;
        std::string s_; // full column name
        int integer_num;
    };

    class Exp {
    public:
        virtual ~Exp();

        virtual bool visit(AbstractExpProcessor *processor) =0;

        void setValue(Value v);

        [[nodiscard]] Value getValue();

        [[nodiscard]] ExpType getExpType() const { return expType; }

    protected:
        explicit Exp(ExpType type_);

        Value value_;

    private:
        ExpType expType;
    };


    class BetweenExpr : public Exp {
    public:
        BetweenExpr(Exp *exp1_, Exp *exp2_, Exp *exp3_);

        bool visit(AbstractExpProcessor *processor) override;

        [[nodiscard]] Exp *getExp1() const { return exp1; }
        [[nodiscard]] Exp *getExp2() const { return exp2; }
        [[nodiscard]] Exp *getExp3() const { return exp3; }

    private:
        Exp *exp1, *exp2, *exp3;
    };


    class BinaryExp : public Exp {
    public:
        BinaryExp(BinaryExpType type_, Exp *left_, Exp *right_);

        [[nodiscard]] BinaryExpType binaryType() const;

        bool visit(AbstractExpProcessor *processor) override;

        [[nodiscard]] Exp *getLeft() const { return left; }
        [[nodiscard]] Exp *getRight() const { return right; }

    private:
        BinaryExpType type;
        Exp *left, *right;
    };

    class UnaryExp : public Exp {
    public:
        UnaryExp(UnaryExpType type_, Exp *exp_);

        [[nodiscard]] UnaryExpType unaryType() const;

        bool visit(AbstractExpProcessor *processor) override;

        [[nodiscard]] Exp *getExp() const { return exp; }

    private:
        Exp *exp;
        UnaryExpType type;
    };


    class ScalarExp : public Exp {
    public:
        explicit ScalarExp(ColumnName *column_name_);

        explicit ScalarExp(char *);

        explicit ScalarExp(int);

        explicit ScalarExp();

        explicit ScalarExp(double);

        [[nodiscard]] ScalarType scalarType() const;

        bool visit(AbstractExpProcessor *processor) override;

        [[nodiscard]] ScalarType getType() const { return type; }

        [[nodiscard]] int getInteger() const { return integer; }

        [[nodiscard]] double getFloat() const { return d; }

        [[nodiscard]] std::string getStr() const { return str; }

        [[nodiscard]] ColumnName *getColumnName() const { return column_name; }

        void setFullColumnName(ColumnFullName column_full_name) { full_name_ = std::move(column_full_name); }

        ColumnFullName getColumnFullName() { return full_name_; }

    private:
        ScalarType type;
        ColumnName *column_name;
        char *str;
        int integer;
        double d;
        ColumnFullName full_name_;
    };
}
#endif //EXP_H
