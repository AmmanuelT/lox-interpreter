
#include "Token.h"
#include "Visitor.h"
#include "TokenType.h"
#include "Expr.h"
#include "Token.h"
#include <iostream>
#include "AstPrinter.h"

std::string Unary::accept(Visitor *visitor){
    return visitor->visitUnaryExpr(this);
};

std::string Binary::accept(Visitor *visitor){
    return visitor->visitBinaryExpr(this);
};

std::string Grouping::accept(Visitor *visitor){
    return visitor->visitGroupingExpr(this);
};

std::string Literal::accept(Visitor *visitor){
    return visitor->visitLiteralExpr(this);
};

std::string Unary::accept(AstPrinter* visitor){
    return visitor->visitUnaryExpr(this);
};

std::string Binary::accept(AstPrinter* visitor){
    return visitor->visitBinaryExpr(this);
};

std::string Grouping::accept(AstPrinter* visitor){
    return visitor->visitGroupingExpr(this);
};

std::string Literal::accept(AstPrinter* visitor){
    return visitor->visitLiteralExpr(this);
};




