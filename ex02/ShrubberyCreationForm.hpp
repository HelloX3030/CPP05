#pragma once

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
    private:
        void special_action() override;

    public:
        ShrubberyCreationForm(std::string target);
};
