#pragma once

#include <string>
#include <exception>
#include <iostream>

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

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const noexcept override;
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const noexcept override;
        };
};
