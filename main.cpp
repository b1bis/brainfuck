#include <iostream>
#include <fstream>
#include "BFMachine.hpp"

int main(int argc, char** argv)
{
    std::string code;
    if(argc == 2)
    {
        std::string scriptsPath = argv[1];
        std::ifstream file(scriptsPath);
        
        if(!file.is_open())
        {
            std::cerr << "Can't open file " << scriptsPath << std::endl;
            return EXIT_FAILURE;
        }
        code = std::string(std::istreambuf_iterator<char>(file)
        , std::istreambuf_iterator<char>());
    }
    else
    {
        std::cout << ">>> ";
        std::getline(std::cin, code);
    }

    BF::Machine machine;
    machine.Execute(code);
    return EXIT_SUCCESS;
}