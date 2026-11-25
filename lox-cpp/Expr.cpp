
#include "Token.h"
#include "Visitor.h"
#include "TokenType.h"
#include "Expr.h"
#include "Token.h"
#include <iostream>


template<typename R> R Unary::accept(Visitor<R> *visitor){
    return visitor->visitUnaryExpr(this);
};

template<typename R> R Binary::accept(Visitor<R> *visitor){
    return visitor->visitBinaryExpr(this);
};

template<typename R> R Grouping::accept(Visitor<R> *visitor){
    return visitor->visitGroupingExpr(this);
};

template<typename R> R Literal::accept(Visitor<R> *visitor){
    return visitor->visitLiteralExpr(this);
};




