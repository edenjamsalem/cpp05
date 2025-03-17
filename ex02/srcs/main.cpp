#include "../includes/AForm.hpp"

int main()
{
	Bureaucrat eden("Eden", 1);
	Bureaucrat john("John", 140);
	AForm form("form1", 120, 110);

	std::cout << eden;
	std::cout << form;

	eden.signForm(form);
	john.signForm(form);
}
