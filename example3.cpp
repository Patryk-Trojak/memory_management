#include <iostream>
#include <stdexcept>
#include <memory>

void validateArguments(int argc)
{
    if(argc != 2)
    {
        std::cerr << "You need to pass 1 argument" << std::endl;
        exit(-1);
    }
}

class Wrong_Argument_Exception
    : public std::logic_error
{
public:  
    Wrong_Argument_Exception() 
    : std::logic_error("Passed d. d is prohibited."){};
};

class Resource
{
public:
    void use(const char* arg)
    {
        std::cout << "Using resource. Passed " << *arg << std::endl;
        if (*arg == 'd')
        {
            throw Wrong_Argument_Exception();
        }
    }
};

int main(int argc, char* argv[])
{
    validateArguments(argc);

    const char* argument = argv[1];

    try
    {
        auto rsc = std::make_unique<Resource>();
        rsc->use(argument);
    }
    catch (std::logic_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

