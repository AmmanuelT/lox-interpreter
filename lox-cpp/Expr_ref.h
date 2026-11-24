#include "Token.h"

class Expr_ref {
    
};

class Unary_ref : public Expr_ref {
    const Expr_ref left;
    const Token op;
    const Expr_ref right;

    Unary_ref(Expr_ref left, Token op, Expr_ref right):
    left(left), op(op), right(right)
    {}
};