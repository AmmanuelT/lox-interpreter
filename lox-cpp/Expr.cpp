
#include "Token.h"
#include "Visitor.h"
#include "TokenType.h"
#include "Expr.h"
#include "Token.h"
#include <any>
#include <iostream>
#include "AstPrinter.h"

std::any UnaryExpr::accept(std::shared_ptr<Visitor<std::any>> visitor) const{
    return visitor->visitUnaryExpr(*this);
};

// std::any BinaryExpr::accept(Visitor<std::any>& visitor) const{
//     return visitor.visitBinaryExpr(*this);
// };

// std::any GroupingExpr::accept(Visitor<std::any>& visitor) const{
//     return visitor.visitGroupingExpr(*this);
// };

// std::any LiteralExpr::accept(Visitor<std::any>& visitor) const{
//     return visitor.visitLiteralExpr(*this);
// };




