#ifndef EXPR_H
#define EXPR_H
#include "Token.h"
#include "TokenType.h"
#include "AstPrinter.h"
#include "Visitor.h"
#include <memory>


template<typename R> class Visitor;
class AstPrinter;

class Expr {
    public:
    virtual std::any accept(std::shared_ptr<Visitor<std::any>> visitor) const;
};

// class BinaryExpr : public Expr{
//     public:
//     const Expr left;
//     const Token op;
//     const Expr right;
//     BinaryExpr (Expr left, Token op, Expr right):
//     left(left), op(op), right(right)
//     {}
//     virtual std::any  accept(Visitor<std::any>& visitor) const;

// };

// class GroupingExpr : public Expr{
//     public:
//     const Expr expression;
//     GroupingExpr(Expr expression):
//     expression(expression)
//     {}
//     virtual std::any  accept(Visitor<std::any>& visitor) const;
// };

class LiteralExpr : public Expr{
    public:
    const std::string value;
    LiteralExpr(std::string value):
    value(value)
    {}
    virtual std::any accept(std::shared_ptr<Visitor<std::any>> visitor) const;
};

class UnaryExpr : public Expr{
    public:
    const Token op;
    const Expr right;
    UnaryExpr(Token op, Expr right):
    op(op), right(right)
    {}
    virtual std::any accept(std::shared_ptr<Visitor<std::any>> visitor) const;
};




#endif



