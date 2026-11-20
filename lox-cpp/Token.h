#ifndef TOKEN_H_
#define TOKEN_H_
#include <iostream>
#include "TokenType.h"

class Token{
    const TokenType type;
    const std::string lexeme;
    const std::string literal;
    const int line;
public:
    Token(TokenType type, std::string lexeme,std::string literal, int line);
    std::string toString();
};

#endif