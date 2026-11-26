#include "Expr.h"
#include "Visitor.h"
#include "Token.h"
#include "TokenType.h"
#include "AstPrinter.h"
#include <iostream>
#include <memory>



std::string AstPrinter::print(const Expr& expr) const{
    std::shared_ptr<Visitor<std::any>> visitor = std::make_shared<Visitor<std::any>>(*this);;
    return std::any_cast<std::string>(expr.accept(visitor));
}

// std::string AstPrinter::visitBinaryExpr(const BinaryExpr& expr) const{
//     const std::vector<const Expr&> exprs = {expr.left, expr.right};
//     std::string name = expr.op.lexeme;
//     return parenthesize(exprs, name);
// }


// std::string AstPrinter::visitGroupingExpr(const GroupingExpr& expr) const{
//     std::vector<Expr> exprs = {expr->expression};
//     std::string name = "group";
//     return parenthesize(exprs, name);
// }


std::string AstPrinter::visitLiteralExpr(const LiteralExpr& expr) const{
    return expr.value;
}


std::string AstPrinter::visitUnaryExpr(const UnaryExpr& expr) const{
    std::vector<Expr> exprs = { expr.right};
    std::string name = expr.op.lexeme;
    return parenthesize( exprs, name);
}

std::string AstPrinter::parenthesize(const std::vector<Expr>& exprs, std::string name)const{
    std::string builder ;
    std::shared_ptr<Visitor<std::any>> visitor = std::make_shared<Visitor<std::any>>(*this);

    builder +=  "(";
    builder += name;
    for (Expr expr : exprs) {
        builder += " ";
        builder += std::any_cast<std::string>(expr.accept(visitor));
    }
    builder += ")";

    return builder;
}




void Test() {
    // const Expr expression = new Binary(
    //     Unary(
    //         Token(MINUS, "-", "", 1),
    //         Literal("123")),
    //     Token(STAR, "*", "", 1),
    //     Grouping(
    //         Literal("45.67")));
    const Expr expression = UnaryExpr(Token(MINUS, "-", "", 1), LiteralExpr("45.67"));
    AstPrinter printer = AstPrinter();
    std::cout << printer.print(expression);
    std::cout << "test";
}
