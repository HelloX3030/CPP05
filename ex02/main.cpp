#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

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
        Bureaucrat john("John Dumb 2", 146);
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
        Bureaucrat john("John Smith 3", 1);
        std::cout << john << std::endl;
        john.signForm(h);
        h.execute(john);
        std::cout << h << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << "Test4" << std::endl;
    try
    {
        RobotomyRequestForm r("Robotus Formu 0");
        std::cout << r << std::endl;
        Bureaucrat john("John Robot 0", 1);
        std::cout << john << std::endl;
        john.signForm(r);
        r.execute(john);
        std::cout << r << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl << "Test5" << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        try
        {
            RobotomyRequestForm r("Robotus Formu " + std::to_string(i));
            std::cout << r << std::endl;
            Bureaucrat john("John Robot " + std::to_string(i), 1);
            john.signForm(r);
            r.execute(john);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}
