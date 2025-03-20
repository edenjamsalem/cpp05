#include "../includes/Form.hpp"

Form::Form()
	: _name("default"), _signed(false) {}

Form::Form(std::string name, int s_grade, int e_grade)
	: _name(name), _signed(false), _signed_grade(s_grade), _execute_grade(e_grade) {}

Form::Form(const Form& other)
{
	_signed = other._signed;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return *this;
}

Form::~Form() {}


std::string Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_signed);
}

int Form::getSignedGrade() const
{
	return (_signed_grade);
}

int Form::getExecuteGrade() const
{
	return (_execute_grade);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signed_grade)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::ostream &operator <<(std::ostream &os, Form &form)
{
	os << "Form: "<< form.getName() << ", ";
	os << "signedGrade: " << form.getSignedGrade() << ", ";
	os << "executeGrade: " << form.getExecuteGrade() << ", ";
	os << "isSigned: " << form.getIsSigned();
	return (os);
}
