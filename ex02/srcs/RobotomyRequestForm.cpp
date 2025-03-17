#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:	AForm("RobotomyRequestForm", 72, 45), _target("default_target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:	AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		_target = other._target;

	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}


