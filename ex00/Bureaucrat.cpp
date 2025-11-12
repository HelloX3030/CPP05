#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException(name);
    if (grade > 150)
        throw GradeTooLowException(name);
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : msg("Grade too high") { }

Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException& other)
{
    msg = other.msg;
}

Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException& other)
{
    if (this != &other)
    {
        msg = other.msg;
    }
    return *this;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& name)
{
    msg = "Grade too high for Bureaucrat \"" + name + "\"";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() : msg("Grade too low") {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException& other)
{
    msg = other.msg;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return msg.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& name)
{
    msg = "Grade too low for Bureaucrat \"" + name + "\"";
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() {}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return msg.c_str();
}
