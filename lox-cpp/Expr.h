#ifndef EXPR_H
#define EXPR_H
#include "Token.h"
#include "TokenType.h"
#include "AstPrinter.h"
#include "Visitor.h"

class Visitor;
class AstPrinter;

class Expr {
    public:
    virtual std::string accept(Visitor *visitor);
    virtual std::string accept(AstPrinter* visitor);
};

class Binary : public Expr{
    public:
    const Expr left;
    const Token op;
    const Expr right;
    Binary(Expr left, Token op, Expr right):
    left(left), op(op), right(right)
    {}
    std::string accept(Visitor *visitor);
    std::string accept(AstPrinter* visitor);
};

class Grouping : public Expr{
    public:
    const Expr expression;
    Grouping(Expr expression):
    expression(expression)
    {}
    std::string accept(Visitor *visitor);
    std::string accept(AstPrinter* visitor);
};

class Literal : public Expr{
    public:
    const std::string value;
    Literal(std::string value):
    value(value)
    {}
    std::string accept(Visitor *visitor);
    std::string accept(AstPrinter* visitor);
};

class Unary : public Expr{
    public:
    const Token op;
    const Expr right;
    Unary(Token op, Expr right):
    op(op), right(right)
    {}
    std::string accept(Visitor *visitor);
    std::string accept(AstPrinter* visitor);
};




#endif



