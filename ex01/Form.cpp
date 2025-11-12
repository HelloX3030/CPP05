#include "Form.hpp"

Form::Form() : name("Default Form"), is_signed(false), sign_grade(150), exec_grade(150) {}

Form::Form(const Form &other)
    : name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), exec_grade(other.exec_grade) {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        is_signed = other.is_signed;
    }
    return *this;
}

Form::Form(const std::string name, int signGrade, int execGrade)
    : name(name), is_signed(false), sign_grade(signGrade), exec_grade(execGrade) {}


Form::~Form() {}

std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return is_signed;
}

int Form::getSignGrade() const
{
    return sign_grade;
}

int Form::getExecGrade() const
{
    return exec_grade;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form Name: " << form.getName() << "\n"
       << "Is Signed: " << (form.getIsSigned() ? "Yes" : "No") << "\n"
       << "Sign Grade: " << form.getSignGrade() << "\n"
       << "Execution Grade: " << form.getExecGrade();
    return os;
}
