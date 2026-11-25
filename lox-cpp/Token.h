#ifndef TOKEN_H_
#define TOKEN_H_
#include <iostream>
#include "TokenType.h"
#include <any>

class Token{
public:
    const TokenType type;
    const std::string lexeme;
    const std::any literal;
    const int line;
    Token(TokenType type, std::string lexeme, int line);
    Token(TokenType type, std::string lexeme,std::any literal, int line);
    std::string toString();
    std::string literalToString();
};

#endif