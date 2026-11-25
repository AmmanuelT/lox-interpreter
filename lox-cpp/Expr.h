#ifndef EXPR_H
#define EXPR_H
#include "Token.h"
#include "TokenType.h"


template<typename R> class Visitor;

class Expr {
    public:
    template<typename R> R accept(Visitor<R> *visitor);
    
};

class Binary : public Expr{
    public:
    const Expr left;
    const Token op;
    const Expr right;
    Binary(Expr left, Token op, Expr right):
    left(left), op(op), right(right)
    {}
    template<typename R> R accept(Visitor<R> *visitor);
};

class Grouping : public Expr{
    public:
    const Expr expression;
    Grouping(Expr expression):
    expression(expression)
    {}
    template<typename R> R accept(Visitor<R> *visitor);
};

class Literal : public Expr{
    public:
    const std::string value;
    Literal(std::string value):
    value(value)
    {}
    template<typename R> R accept(Visitor<R> *visitor);
};

class Unary : public Expr{
    public:
    const Token op;
    const Expr right;
    Unary(Token op, Expr right):
    op(op), right(right)
    {}
    template<typename R> R accept(Visitor<R> *visitor);
};




#endif



