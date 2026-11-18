#include<iostream>

class Lox{
    public:
    void main(int argc, char* argv[]){
        if (argc > 1){
            std::cout << "Usage: jlox [script]" << "\n";
        } else if ( argc == 1) {
            //runFile(argv[0]);
        } else{
            //runPrompt();
        }
    }
};

int main(int argc, char* argv[]){
    Lox lox = Lox();
    lox.main(argc,argv);
}
