#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("Eden"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade()
{
	return (_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

void	Bureaucrat::incrementGrade()
{
	setGrade(_grade - 1);
}

void	Bureaucrat::decrementGrade()
{
	setGrade(_grade + 1);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!\n");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!\n");
}

std::ostream &operator <<(std::ostream &os, Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return (os);
}

void Bureaucrat::signForm(AForm &form)
{
	try 
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form << std::endl;
	}
	catch (std::exception &err)
	{
		std::cerr << getName() << " couldn't sign " << form << " because " << err.what() << std::endl;
	}
}