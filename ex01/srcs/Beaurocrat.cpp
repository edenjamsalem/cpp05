#include "../includes/Beaurocrat.hpp"

Beaurocrat::Beaurocrat()
	: _name("Eden"), _grade(150) {}

Beaurocrat::Beaurocrat(std::string name, int grade) : _name(name)
{
	setGrade(grade);
}

Beaurocrat::Beaurocrat(const Beaurocrat& other)
	: _name(other._name), _grade(other._grade) {}

Beaurocrat& Beaurocrat::operator=(const Beaurocrat& other)
{
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Beaurocrat::~Beaurocrat() {}

const std::string	Beaurocrat::getName() const
{
	return (_name);
}

int	Beaurocrat::getGrade()
{
	return (_grade);
}

void	Beaurocrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

void	Beaurocrat::incrementGrade()
{
	setGrade(_grade - 1);
}

void	Beaurocrat::decrementGrade()
{
	setGrade(_grade + 1);
}

const char	*Beaurocrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!\n");
}

const char	*Beaurocrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!\n");
}

std::ostream &operator <<(std::ostream &os, Beaurocrat &beaurocrat)
{
	os << beaurocrat.getName() << ", beaurocrat grade " << beaurocrat.getGrade() << ".\n";
	return (os);
}

void Beaurocrat::signForm(Form &form)
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