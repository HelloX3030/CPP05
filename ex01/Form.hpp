#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Form
{
private:
    const std::string name;
    bool is_signed;
    const int sign_grade;
    const int exec_grade;

public:
    // Constructors
    Form();
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    // Special Constructors
    Form(const std::string name, int signGrade, int execGrade);

    // Functions
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    class GradeTooHighException : public std::exception
    {
        private:
            std::string msg;

        public:
            // Constructors
            GradeTooHighException();
            GradeTooHighException(const GradeTooHighException &other);
            GradeTooHighException &operator=(const GradeTooHighException &other);
            ~GradeTooHighException();

            // Special Constructors
            GradeTooHighException(const std::string name);

            // Functions
            const char *what() const noexcept override;
    };

    class GradeTooLowException : public std::exception
    {
        private:
            std::string msg;

        public:
            // Constructors
            GradeTooLowException();
            GradeTooLowException(const GradeTooLowException &other);
            GradeTooLowException &operator=(const GradeTooLowException &other);
            ~GradeTooLowException();

            // Special Constructors
            GradeTooLowException(const std::string name);

            // Functions
            const char *what() const noexcept override;
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);
