#ifndef AST_PRINTER
#define AST_PRINTER

#include <iostream>
#include "Visitor.h"
#include <any>

class AstPrinter : public Visitor<std::any> {
  public:
  //std::string visit(Expr* expr);

  std::string print(const Expr& expr) const;

//   std::string visitBinaryExpr(const BinaryExpr& expr) const;
  
//   std::string visitGroupingExpr(const GroupingExpr& expr);

  
  std::string visitLiteralExpr(const LiteralExpr& expr) const;

  std::string visitUnaryExpr(const UnaryExpr& expr) const;

  std::string parenthesize(const std::vector<Expr>& exprs, std::string name) const;

};

void Test();

#endif