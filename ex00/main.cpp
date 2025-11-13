#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "Test1" << std::endl;
    try
    {
        Bureaucrat b("Smart af", -100);
        std::cout << "Created Bureaucrat: " << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl <<"Test2" << std::endl;
    try
    {
        Bureaucrat b("Dumb af", 100000);
        std::cout << "Created Bureaucrat: " << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl <<"Test3" << std::endl;
    try
    {
        Bureaucrat b("smartus rex", 1);
        std::cout << "Created Bureaucrat: " << b << std::endl;
        ++b;
        std::cout << "After increment: " << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl <<"Test4" << std::endl;
    try
    {
        Bureaucrat b("dumbus maximus", 150);
        std::cout << "Created Bureaucrat: " << b << std::endl;
        --b;
        std::cout << "After decrement: " << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl <<"Test5" << std::endl;
    try
    {
        Bureaucrat b("new bureaucrat", 75);
        std::cout << "Created Bureaucrat: " << b << std::endl;
        ++b;
        std::cout << "After increment: " << b << std::endl;
        --b;
        std::cout << "After decrement: " << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
