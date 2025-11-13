#pragma once

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
    private:
        void special_action() const override;

    public:
        ShrubberyCreationForm(std::string target);
};
