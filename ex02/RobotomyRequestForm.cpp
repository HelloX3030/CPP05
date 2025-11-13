#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target + "_robotomy", 72, 45)
{
    std::srand(seed);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    std::srand(seed);
}

RobotomyRequestForm::RobotomyRequestForm()
    : AForm()
{
    std::srand(seed);
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        seed = other.seed;
    }
    return *this;
}

void RobotomyRequestForm::special_action() const
{
    std::cout << DRILLING_NOISE << std::endl;
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    int num = dist(gen);
    if (num <= 50)
        std::cout << "\"" << getName() << "\" has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on \"" << getName() << "\"." << std::endl;
}
