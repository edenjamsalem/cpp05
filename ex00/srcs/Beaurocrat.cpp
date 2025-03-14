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
		throw GradeTooHighError();
	else if (grade > 150)
		throw GradeTooLowError();
	else
		_grade = grade;
}

void	Beaurocrat::incrementGrade()
{
	if (_grade > 1)
		_grade--;
}

void	Beaurocrat::decrementGrade()
{
	if (_grade < 150)
		_grade++;
}

const char	*Beaurocrat::GradeTooHighError::what() const throw()
{
	return ("Grade too high!\n");
}

const char	*Beaurocrat::GradeTooLowError::what() const throw()
{
	return ("Grade too low!\n");
}

std::ostream &operator <<(std::ostream &os, Beaurocrat &beaurocrat)
{
	os << beaurocrat.getName() << ", beaurocrat grade " << beaurocrat.getGrade() << ".\n";
	return (os);
}