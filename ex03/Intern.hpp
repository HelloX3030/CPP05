#pragma once

#include <string>

class AForm;

class Intern
{
    public:
        // Constructors
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        // Functions
        AForm* makeForm(const std::string formName, const std::string target) const;
};
