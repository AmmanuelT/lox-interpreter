#include "Expr.h"
#include "Visitor.h"
#include "Token.h"
#include "TokenType.h"
#include "AstPrinter.h"
#include <iostream>



std::string AstPrinter::print(Expr* expr) {
    return expr->accept(this);
}

std::string AstPrinter::visitBinaryExpr(Binary* expr) {
    std::vector<Expr> exprs = {expr->left, expr->right};
    std::string name = expr->op.lexeme;
    return parenthesize(exprs, name);
}


std::string AstPrinter::visitGroupingExpr(Grouping* expr) {
    std::vector<Expr> exprs = {expr->expression};
    std::string name = "group";
    return parenthesize(exprs, name);
}


std::string AstPrinter::visitLiteralExpr(Literal* expr) {
    return expr->value;
}


std::string AstPrinter::visitUnaryExpr(Unary* expr) {
    std::vector<Expr> exprs = { expr->right};
    std::string name = expr->op.lexeme;
    return parenthesize( exprs, name);
}

std::string AstPrinter::parenthesize(std::vector<Expr> exprs, std::string name) {
    std::string builder ;

    builder +=  "(";
    builder += name;
    for (Expr expr : exprs) {
        builder += " ";
        builder += expr.accept(this);
    }
    builder += ")";

    return builder;
}




void Test() {
    Expr expression = Binary(
        Unary(
            Token(MINUS, "-", "", 1),
            Literal("123")),
        Token(STAR, "*", "", 1),
        Grouping(
            Literal("45.67")));
    AstPrinter printer = AstPrinter();
    std::cout << printer.print(expression);
    std::cout << "test";
}
