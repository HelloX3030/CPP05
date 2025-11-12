#pragma once

#include <string>
#include <exception>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:
        // Constructors
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        // Special Constructor
        Bureaucrat(std::string name, int grade);

        // Functions
        std::string getName() const;
        int getGrade() const;
};
