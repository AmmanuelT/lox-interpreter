#include <cctype>
#include <iostream>
#include "Token.h"
#include "TokenType.h"
#include "Scanner.h"
#include "lox.h"

Scanner::Scanner(std::string source):
source(source)
{}

std::vector<Token> Scanner::scanTokens(){
    while( !isAtEnd()){
        start = current;
        scanToken();
    }
    TokenType end = EOF_;
    tokens.push_back(Token(EOF_, "", "", line));
    return tokens;
}

bool Scanner::isAtEnd(){
    return current >= source.size();
}

void Scanner::scanToken() {
char c = advance();
        switch (c) {
            case '(': addToken(LEFT_PAREN); break;
            case ')': addToken(RIGHT_PAREN); break;
            case '{': addToken(LEFT_BRACE); break;
            case '}': addToken(RIGHT_BRACE); break;
            case ',': addToken(COMMA); break;
            case '.': addToken(DOT); break;
            case '-': addToken(MINUS); break;
            case '+': addToken(PLUS); break;
            case ';': addToken(SEMICOLON); break;
            case '*': addToken(STAR); break; 
            case '!':
                addToken(match('=') ? BANG_EQUAL : BANG);
                break;
            case '=':
                addToken(match('=') ? EQUAL_EQUAL : EQUAL);
                break;
            case '<':
                addToken(match('=') ? LESS_EQUAL : LESS);
                break;
            case '>':
                addToken(match('=') ? GREATER_EQUAL : GREATER);
                break;
            case '/':
                if (match('/')) {
                    // A comment goes until the end of the line.
                    while (peek() != '\n' && !isAtEnd()) advance();
                } else if (match ('*')) {
                    while (peek() != '*' && peekNext() != '/') advance();
                    advance();
                    advance();
                }else {
                    addToken(SLASH);
                }
                break;
            case '\"': string(); break;
            case ' ':
            case '\r':
            case '\t':
                // Ignore whitespace.
                break;

            case '\n':
                line++;
                break;
            default:
                if(isdigit(c)){
                    number();
                } else if (isalpha(c)){
                    identifier();
                } else {
                    Lox::error(line, "Unexpected character.");
                    break;
                }
                
        }
}

bool Scanner::match(char expected){
    if(isAtEnd()) return false;
    if(source.at(current)!= expected) return false;

    current++;
    return true;
}

char Scanner::peek(){
    if(isAtEnd()) return '\n';
    return source.at(current);
}

char Scanner::peekNext() {
    if (current + 1 >= source.length()) return '\0';
    return source.at(current + 1);
}

char Scanner::advance(){
    return source.at(current++);
}

void Scanner::addToken(TokenType type){
    addToken(type, "");
}

void Scanner::addToken(TokenType type, std::string literal){
    std::string text = source.substr(start, current);
    tokens.push_back(Token(type, text, literal, line));
}

void Scanner::string() {
    while (peek() != '"' && !isAtEnd()) {
      if (peek() == '\n') line++;
      advance();
    }

    if (isAtEnd()) {
      Lox::error(line, "Unterminated string.");
      return;
    }

    // The closing ".
    advance();

    // Trim the surrounding quotes.
    std::string value = source.substr(start + 1, current - 1);
    addToken(STRING, value);
  }

void Scanner::number() {
    while (isdigit(peek())) advance();

    if (peek() == '.' and isdigit(peekNext())) {
        advance();
        while (isdigit(peek())) advance();
    }
    // Trim the surrounding quotes.
    std::string value = source.substr(start, current);
    addToken(NUMBER, value);
}

std::unordered_map<std::string, TokenType> keywords = {
    {"and" , AND},
    {"class", CLASS},
    {"else", ELSE},
    {"false",  FALSE},
    {"fun", FUN}, 
    {"for", FOR},
    {"if",       IF},
    {"nil",       NIL},
    {"or",        OR},
    {"print",    PRINT},
    {"return", RETURN},
    {"super",  SUPER},
    {"this",   THIS},
    {"true",   TRUE},
    {"var",    VAR},
    {"while",  WHILE}
};

void Scanner::identifier(){
    while(isalpha(peek())) advance();
    std::string value = source.substr(start, current);
    if(keywords.find(value) != keywords.end()){
        addToken(keywords.at(value));
    } else {
        addToken(IDENTIFIER, value);
    }
}