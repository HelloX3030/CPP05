#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    try
    {
        Intern intern;
        AForm* f = intern.makeForm("shrubbery creation", "home");
        if (f)
        {
            std::cout << *f << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Intern intern;
        AForm* f = intern.makeForm("Yeeeeeeeeeeeeeet Norm", "Normed Yeet");
        if (f)
        {
            std::cout << *f << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
