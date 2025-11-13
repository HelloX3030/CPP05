#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    std::cout << "Test1" << std::endl;
    try
    {
        ShrubberyCreationForm h("home");
        std::cout << h << std::endl;
        Bureaucrat john("John", 1);
        std::cout << john << std::endl;
        h.execute(john);
        john.signForm(h);
        h.execute(john);
        std::cout << h << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << "Test2" << std::endl;
    try
    {
        ShrubberyCreationForm h("home2");
        std::cout << h << std::endl;
        Bureaucrat john("John Smith 2", 1);
        std::cout << john << std::endl;
        john.signForm(h);
        h.execute(john);
        std::cout << h << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << "Test3" << std::endl;
    try
    {
        ShrubberyCreationForm h("home3");
        std::cout << h << std::endl;
        Bureaucrat john("John Dumb 3", 146);
        std::cout << john << std::endl;
        john.signForm(h);
        h.execute(john);
        std::cout << h << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
