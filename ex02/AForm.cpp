#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default AForm"), is_signed(false), sign_grade(150), exec_grade(150)
{
}

AForm::AForm(const AForm &other)
    : name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), exec_grade(other.exec_grade)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        is_signed = other.is_signed;
    }
    return *this;
}

AForm::AForm(const std::string name, int signGrade, int execGrade)
    : name(name), is_signed(false), sign_grade(signGrade), exec_grade(execGrade)
{
    if (sign_grade < 1 || exec_grade < 1)
        throw AForm::GradeTooHighException(name);
    if (sign_grade > 150 || exec_grade > 150)
        throw AForm::GradeTooLowException(name);
}


AForm::~AForm() {}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return is_signed;
}

int AForm::getSignGrade() const
{
    return sign_grade;
}

int AForm::getExecGrade() const
{
    return exec_grade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= sign_grade)
    {
        is_signed = true;
    }
    else
        throw AForm::GradeTooLowException(name, bureaucrat.getName());
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > exec_grade)
        throw AForm::GradeTooLowException(name, executor.getName());
    if (!is_signed)
        throw std::runtime_error("Error: Form is not signed");
    special_action();
}

AForm::GradeTooHighException::GradeTooHighException() : msg("Error: Grade is too high") {}

AForm::GradeTooHighException::GradeTooHighException(const GradeTooHighException &other) : msg(other.msg) {}

AForm::GradeTooHighException &AForm::GradeTooHighException::operator=(const GradeTooHighException &other)
{
    if (this != &other)
    {
        msg = other.msg;
    }
    return *this;
}

AForm::GradeTooHighException::~GradeTooHighException() {}

AForm::GradeTooHighException::GradeTooHighException(const std::string name) : msg("Error: Grade is too high for \"" + name + "\"") {}

const char *AForm::GradeTooHighException::what() const noexcept
{
    return msg.c_str();
}

AForm::GradeTooLowException::GradeTooLowException() : msg("Error: Grade is too low") {}

AForm::GradeTooLowException::GradeTooLowException(const GradeTooLowException &other) : msg(other.msg) {}

AForm::GradeTooLowException &AForm::GradeTooLowException::operator=(const GradeTooLowException &other)
{
    if (this != &other)
    {
        msg = other.msg;
    }
    return *this;
}

AForm::GradeTooLowException::~GradeTooLowException() {}

AForm::GradeTooLowException::GradeTooLowException(const std::string name) : msg("Error: Grade is too low for \"" + name + "\"") {}

AForm::GradeTooLowException::GradeTooLowException(const std::string name, const std::string bureaucratName)
    : msg("Error: Grade is too low for \"" + name + "\" when signed by \"" + bureaucratName + "\"") {}

const char *AForm::GradeTooLowException::what() const noexcept
{
    return msg.c_str();
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "(\"" << form.getName()
       << "\" Is Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << " | Sign Grade: " << form.getSignGrade()
       << " | Execution Grade: " << form.getExecGrade() << ")";
    return os;
}
