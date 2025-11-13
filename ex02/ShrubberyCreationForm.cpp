#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target + "_shrubbery", 145, 137)
{
}

void ShrubberyCreationForm::special_action() const
{
    std::ofstream file(getName());
    if (!file) return;

    file << TREE_ASCII;

    file.close();
}
