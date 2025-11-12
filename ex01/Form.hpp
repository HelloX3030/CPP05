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
};

std::ostream &operator<<(std::ostream &os, const Form &form);
