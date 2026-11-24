#include "Token.h" 
class Expr {};
class Binary : public Expr{
    const Expr left;
    const Token op;
    const Expr right;
    Binary():
    left(left), op(op), right(right)
{}
};