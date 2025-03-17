#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
	Intern someRandomIntern;
	AForm	*form;

	form = someRandomIntern.makeForm("ShrubberyCreationForm", "Autumn");
	delete form;
	form = someRandomIntern.makeForm("RobotomyRequestForm", "IRobot");
	delete form;
	form = someRandomIntern.makeForm("PresidentialPardonForm", "Andrew Tate");
	delete form;
	form = someRandomIntern.makeForm("UnknownForm", "EEK");
}
