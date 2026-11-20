#ifndef SCANNER_H_
#define SCANNER_H_
#include <iostream>
#include "Token.h"
#include "TokenType.h"

class Scanner{
    const std::string source;
    std::vector<Token> tokens;
    int start = 0;
    int current = 0;
    int line = 1;

    bool isAtEnd();

    void scanToken();

    bool match(char expected);

    char peek();

    char peekNext();

    void addToken(TokenType type);

    void addToken(TokenType type, std::string literal);
    
    char advance();

    void string();

    void number();

    void identifier();
    
public:
    Scanner(std::string source);
    std::vector<Token> scanTokens();

};

#endif