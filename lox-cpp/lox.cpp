#include<iostream>
#include <fstream>



class Lox{
    std::string readFile(std::string path) {
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

    void runFile(std::string path){
        
        std::string fileContents = readFile(path);
        //TODO
        //run(fileContents);

    }

    void runPrompt(){
        std::string line;
        while (true){
            std::cout << ">";
            std::getline(std::cin, line);
            if (line == ""){
                break;
            }
            // TODO
            //run(line);
            std::cout << line << std::endl;

        }
    }

    public:
    void main(int argc, char* argv[]){
        if (argc > 2){
            std::cout << "Usage: jlox [script]" << "\n";
        } else if ( argc == 2) {
            runFile(argv[0]);
        } else{
            runPrompt();
        }
    }
};

int main(int argc, char* argv[]){
    Lox lox = Lox();
    std::cout << argc << std::endl;
    std::cout << argv;
    lox.main(argc,argv);
}
