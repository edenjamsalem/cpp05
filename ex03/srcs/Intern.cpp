#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

void	Intern::formCreateMessage(std::string &form)
{
	std::cout << "Intern creates " << form << std::endl;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string formNames[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};

	int i = 0;
	while (i < 3 && name != formNames[i])
		i++;

	switch (i) {
		case (0):
			formCreateMessage(name);
			return (new ShrubberyCreationForm(target));
		case (1):
			formCreateMessage(name);
			return (new ShrubberyCreationForm(target));
		case (2):
			formCreateMessage(name);
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << "Intern failed to create " << name << " because form does not exist.\n";
			return (NULL);
	}

}
