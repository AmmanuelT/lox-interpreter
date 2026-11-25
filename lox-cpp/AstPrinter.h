#ifndef AST_PRINTER
#define AST_PRINTER
#include "Expr.h"
#include "Visitor.h"
#include <iostream>


class AstPrinter : public Visitor<std::string> {
  public:
  std::string print(Expr expr);

  std::string visitBinaryExpr(Binary *expr);

  
  std::string visitGroupingExpr(Grouping *expr);

  
  std::string visitLiteralExpr(Literal *expr);

  
  std::string visitUnaryExpr(Unary *expr);

  std::string parenthesize(std::vector<Expr> exprs, std::string name);

};


void Test();

#endif