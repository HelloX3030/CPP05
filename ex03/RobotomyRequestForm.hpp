#pragma once

#include "AForm.hpp"

#include <fstream>
#include <random>

#define DRILLING_NOISE "DDDDDDDDDDDDDDDDDDRRRRRRRRRRRRRRRRRRRRRRRRR"

class RobotomyRequestForm : public AForm
{
    private:
        unsigned int seed;
        void special_action() const override;

    public:
        // Constructors
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

        // Special Constructor
        RobotomyRequestForm(std::string target);
};
