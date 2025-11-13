#pragma once

#include "AForm.hpp"

#include <fstream>

class PresidentialPardonForm : public AForm
{
    private:
        const std::string target;

        void special_action() const override;

    public:
        // Constructors
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        
        // Special Constructor
        PresidentialPardonForm(std::string target);
};
