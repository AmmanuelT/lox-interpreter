#ifndef LOX_H_
#define LOX_H_
#include <iostream>

class Lox{
    static bool hadError;

    static void report(int line, std::string where, std::string message);



    static void run(std::string source);

    static std::string readFile(std::string path);

    static void runFile(std::string path);

    static void runPrompt();

public:
    static void main(int argc, char* argv[]);
    static void error(int line, std::string message);
};

#endif