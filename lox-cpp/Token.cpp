#include <iostream>
#include <string>
#include "Token.h"
#include "TokenType.h"


Token::Token(TokenType type, std::string lexeme, int line)
    :type(type), lexeme(lexeme), literal({}), line(line)
{}

Token::Token(TokenType type, std::string lexeme,std::any literal, int line)
    :type(type), lexeme(lexeme), literal(literal), line(line)
{}

std::string Token::toString() 
{ 
    return ::toString(type) + ", lexeme: '" + lexeme +"', literal: '" + literalToString();
}

std::string Token::literalToString(){
    // inspired by eliasdaler
    switch (type) {
        case TokenType::STRING:
            return std::any_cast<std::string>(literal);
        case TokenType::NUMBER:
            return std::to_string(std::any_cast<double>(literal));
        default:
            return "";
    }
}