#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	:	AForm("ShrubberyCreationForm", 145, 137), _target("default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:	AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		_target = other._target;

	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
