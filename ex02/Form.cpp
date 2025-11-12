#include "Form.hpp"
#include "Bureaucrat.hpp"

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
    : name(name), is_signed(false), sign_grade(signGrade), exec_grade(execGrade)
{
    if (sign_grade < 1 || exec_grade < 1)
        throw Form::GradeTooHighException(name);
    if (sign_grade > 150 || exec_grade > 150)
        throw Form::GradeTooLowException(name);
}


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

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= sign_grade)
    {
        is_signed = true;
    }
    else
        throw Form::GradeTooLowException(name, bureaucrat.getName());
}

Form::GradeTooHighException::GradeTooHighException() : msg("Error: Grade is too high") {}

Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException &other) : msg(other.msg) {}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(const GradeTooHighException &other)
{
    if (this != &other)
    {
        msg = other.msg;
    }
    return *this;
}

Form::GradeTooHighException::~GradeTooHighException() {}

Form::GradeTooHighException::GradeTooHighException(const std::string name) : msg("Error: Grade is too high for \"" + name + "\"") {}

const char *Form::GradeTooHighException::what() const noexcept
{
    return msg.c_str();
}

Form::GradeTooLowException::GradeTooLowException() : msg("Error: Grade is too low") {}

Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException &other) : msg(other.msg) {}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(const GradeTooLowException &other)
{
    if (this != &other)
    {
        msg = other.msg;
    }
    return *this;
}

Form::GradeTooLowException::~GradeTooLowException() {}

Form::GradeTooLowException::GradeTooLowException(const std::string name) : msg("Error: Grade is too low for \"" + name + "\"") {}

Form::GradeTooLowException::GradeTooLowException(const std::string name, const std::string bureaucratName)
    : msg("Error: Grade is too low for \"" + name + "\" when signed by \"" + bureaucratName + "\"") {}

const char *Form::GradeTooLowException::what() const noexcept
{
    return msg.c_str();
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "(\"" << form.getName()
       << "\" Is Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << " | Sign Grade: " << form.getSignGrade()
       << " | Execution Grade: " << form.getExecGrade() << ")";
    return os;
}
