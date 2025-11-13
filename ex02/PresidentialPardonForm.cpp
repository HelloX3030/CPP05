#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target + "_presidential_pardon", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm()
: AForm("default_presidential_pardon", 25, 5), target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other), target(other.target)
{
}

void PresidentialPardonForm::special_action() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
