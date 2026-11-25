#ifndef VISITOR_H
#define VISITOR_H
#include "Expr.h"

template<typename R>
class Visitor{
    R visitUnaryExpr(Unary expr);
    R visitBinaryExpr(Unary expr);
    R visitGroupingExpr(Unary expr);
    R visitLiteralExpr(Unary expr);
};


#endif