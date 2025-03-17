#include "../includes/AForm.hpp"

AForm::AForm()
	: _name("default"), _signed(false) {}

AForm::AForm(std::string name, int s_grade, int e_grade)
	: _name(name), _signed(false), _signed_grade(s_grade), _execute_grade(e_grade) {}

AForm::AForm(const AForm& other)
{
	_signed = other._signed;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return *this;
}

AForm::~AForm() {}


std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_signed);
}

int AForm::getSignedGrade() const
{
	return (_signed_grade);
}

int AForm::getExecuteGrade() const
{
	return (_execute_grade);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signed_grade)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed!");
}

std::ostream &operator <<(std::ostream &os, AForm &form)
{
	os << "AForm: "<< form.getName() << ", ";
	os << "signedGrade: " << form.getSignedGrade() << ", ";
	os << "executeGrade: " << form.getExecuteGrade() << ", ";
	os << "isSigned: " << form.getIsSigned();
	return (os);
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	else	
		execute_action();
}