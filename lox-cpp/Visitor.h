#ifndef VISITOR_H
#define VISITOR_H
#include <iostream>

class Expr;
class BinaryExpr;
class GroupingExpr;
class LiteralExpr;
class UnaryExpr;

template<typename R>
class Visitor{
    public:
    virtual R visitUnaryExpr(const UnaryExpr& expr);
    // virtual R visitBinaryExpr(const BinaryExpr& expr);
    // virtual R visitGroupingExpr(const GroupingExpr& expr);
    virtual R visitLiteralExpr(const LiteralExpr& expr);
};



#endif