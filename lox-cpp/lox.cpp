#include<iostream>
#include <fstream>
#include "lox.h"
#include "Scanner.h"
#include "Token.h"
# include "AstPrinter.h"
bool Lox::hadError = false;

void Lox::report(int line, std::string where, std::string message){
    std::cerr << "[line " << line << "] + Error " << where << ": " << message << std::endl;
    Lox::hadError = true;
}

void Lox::error(int line, std::string message){
    report(line, "", message);
}

void Lox::run(std::string source){
    Scanner scanner(source);
    std::vector<Token> tokens = scanner.scanTokens();

    for (Token token: tokens){
       std::cout << token.toString() << std:: endl;
    }
}

std::string Lox::readFile(std::string path) {
    std::ifstream fileStream(path);

    if (!fileStream.is_open()){
        std::cerr << "Error opening the file!";
        return "";
    }

    std::string fileContents;
    std::string line;
    while(std::getline(fileStream, line)){
        fileContents += line + '\n';
    }

    fileStream.close();
    return fileContents;
}

void Lox::runFile(std::string path){
    
    std::string fileContents = readFile(path);
    run(fileContents);
    if(hadError){
        return;
    }

}

void Lox::runPrompt(){
    std::string line;
    while (true){
        std::cout << ">";
        std::getline(std::cin, line);
        if (line == ""){
            break;
        }
        // TODO
        run(line);
        hadError = false;
    }
}


void Lox::main(int argc, char* argv[]){
    if (argc > 2){
        std::cout << "Usage: jlox [script]" << "\n";
    } else if ( argc == 2) {
        if (strcmp(argv[1], "testParser") == 0){
            Test();
        }  else{
         //runFile(argv[0]);
        }
    } else{
        runPrompt();
    }
    
}


int main(int argc, char* argv[]){
    Lox lox = Lox();
    lox.main(argc,argv);
}
