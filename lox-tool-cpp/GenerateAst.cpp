#include<iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <algorithm>

std::vector<std::string> classes = {
"Binary   : Expr left, Token op, Expr right",
"Grouping : Expr expression",
"Literal  : std::string value",
"Unary    : Token op, Expr right"
};

std::vector<std::string> split(std::string str, std::string token){
    std::vector<std::string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=std::string::npos){
            if(index > token.size()){
                result.push_back(str.substr(0,index));
            }
            str = str.substr(index+token.size());
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

std::string strip(std::string str){
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    return str;

}

std::vector<std::vector<std::string>> splitAttributes(std::string str){
    std::vector<std::vector<std::string>> attributes;

    for (std::string typeAttribute : split(str, ",")){
        std::vector<std::string> sep = split(typeAttribute, " ");
        attributes.push_back({strip(sep[0]), strip(sep[1])});
    }

    return attributes;
}


std::string generateDerived(std::string baseName, std::string className, std::vector<std::vector<std::string>> attributes){
    std::string classDeclaration = "class " + className + " : public " + baseName + "{\n";
    std::string classAttributes = "";
    for (std::vector<std::string> attribute: attributes){
        classAttributes += "    const " + attribute[0] + " " + attribute[1] +";\n";
    }

    std::string classConstructor = "    " + className + "(";

    if (attributes.size() > 0){
        std::string memberInitialization = "";
        std::string classConstructorParameters = "";
        for (std::vector<std::string> attribute: attributes){
            if (memberInitialization.size() > 0) memberInitialization += ", ";
            if (classConstructorParameters.size() > 0) classConstructorParameters += ", ";
            classConstructorParameters += attribute[0] + " " + attribute[1];
            memberInitialization += attribute[1] + "(" + attribute[1] + ")";
        }
        classConstructor += classConstructorParameters + "):\n";
        classConstructor += "    " + memberInitialization + "\n";
    }
    classConstructor += "    {}\n";

    return classDeclaration + classAttributes + classConstructor + "};\n\n";

}

// std::string defineVisitor( std::string baseName, types){
//     std::String
//     return "template<typename R> R accept(Visitor<R> visitor) const";
// };

void defineAst(std::string outputDir, std::string baseName, std::vector<std::string> types){
    std::string path = "../" + outputDir;
    std::ofstream file(path, std::ios::out);
    file << "#include \"Token.h\"\n\n";
    file << "class " + baseName + " {\n";
    file << "    public:\n";
    //file << defineVisitor(baseName);
    file << "};\n\n";
    

    for (std::string str: types){
        std::string type = strip(str.substr(0,str.find(':')));
        std::vector<std::vector<std::string>> attributes = splitAttributes(str.substr(str.find(':') + 1, str.size()));
        file << generateDerived(baseName, type, attributes);
    }
    


    file.close();
}



int main(int argc, char* argv[]){
    if (argc == 1 ){
        std::cerr << "Usage: generate_ast <output directory>" << std::endl;
        return 1;
    }
    std::string outputDir = argv[1];
    defineAst(outputDir, "Expr", classes);

}

