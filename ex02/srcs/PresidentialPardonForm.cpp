#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	:	AForm("PresidentialPardonForm", 24, 5), _target("default_target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	:	AForm("PresidentialPardonForm", 24, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		_target = other._target;

	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::execute_action() const 
{
	std::cout << getTarget() << " has been pardoned by Trumpius Muskimus!\n";
}