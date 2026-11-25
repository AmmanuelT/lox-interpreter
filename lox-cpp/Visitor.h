#ifndef VISITOR_H
#define VISITOR_H
#include <iostream>

class Expr ;
class Binary;
class Grouping;
class Literal;
class Unary;


class Visitor{
    public:
    virtual std::string visit(Expr* expr);
    virtual std::string visitUnaryExpr(Unary* expr);
    virtual std::string visitBinaryExpr(Binary* expr);
    virtual std::string visitGroupingExpr(Grouping* expr);
    virtual std::string visitLiteralExpr(Literal* expr);
};

class AstPrinter : public Visitor {
  public:
  //std::string visit(Expr* expr);

  std::string print(Expr* expr);

  std::string visitBinaryExpr(Binary *expr);
  
  std::string visitGroupingExpr(Grouping *expr);

  
  std::string visitLiteralExpr(Literal *expr);

  
  std::string visitUnaryExpr(Unary *expr);

  std::string parenthesize(std::vector<Expr> exprs, std::string name);

};

#endif