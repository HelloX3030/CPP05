#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string formName, const std::string target) const {
    static std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    int i;
    for (i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
            break;
    }

    AForm* form = nullptr;
    switch (i)
    {
    case 0:
        form = new ShrubberyCreationForm(target);
        break;
    case 1:
        form = new RobotomyRequestForm(target);
        break;
    case 2:
        form = new PresidentialPardonForm(target);
        break;
    default:
        break;
    }
    if (form == nullptr)
        std::cout << "Error: Unknown form name '" << formName << "'." << std::endl;
    return form;
}
