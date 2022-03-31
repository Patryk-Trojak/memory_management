#include <iostream>
#include <stdexcept>

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
    Resource* rsc = nullptr;

    try
    {
        rsc = new Resource();
        rsc->use(argument);
        delete rsc;
    }
    catch (std::logic_error& e)
    {
        delete rsc;
        std::cout << e.what() << std::endl;
    }
    return 0;
}

