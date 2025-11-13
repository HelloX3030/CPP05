#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    std::cout << "Test1" << std::endl;
    try
    {
        Form f("to hard form", -10, -10);
        std::cout << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << "Test2" << std::endl;
    try
    {
        Form f("to easy form", 1000, 1000);
        std::cout << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << "Test3" << std::endl;
    try
    {
        Form f("normal form", 75, 75);
        std::cout << f << std::endl;
        Bureaucrat b("Normal Bureaucrat", 75);
        b.signForm(f);
        b--;
        b.signForm(f);
        b++;
        b++;
        b.signForm(f);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
