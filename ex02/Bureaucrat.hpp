#pragma once

#include <string>
#include <exception>
#include <iostream>

class AForm;

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
        Bureaucrat& operator++();
        Bureaucrat operator++(int);
        Bureaucrat& operator--();
        Bureaucrat operator--(int);
        void signForm(AForm &form);

         class GradeTooHighException : public std::exception {
            private:
                std::string msg;

            public:
                // Constructors
                GradeTooHighException();
                GradeTooHighException(const GradeTooHighException& other);
                GradeTooHighException& operator=(const GradeTooHighException& other);
                ~GradeTooHighException();

                // Special Constructor
                GradeTooHighException(const std::string& name);

                // Functions
                const char* what() const noexcept override;
            };

            class GradeTooLowException : public std::exception {
            private:
                std::string msg;

            public:
                // Constructors
                GradeTooLowException();
                GradeTooLowException(const GradeTooLowException& other);
                GradeTooLowException& operator=(const GradeTooLowException& other);
                ~GradeTooLowException();

                // Special Constructor
                GradeTooLowException(const std::string& name);

                // Functions
                const char* what() const noexcept override;
            };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
