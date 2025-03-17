#include "../includes/Form.hpp"

int main()
{
	Beaurocrat eden("Eden", 1);
	Beaurocrat john("John", 140);
	Form form("form1", 120, 110);

	std::cout << eden;
	std::cout << form;

	eden.signForm(form);
	john.signForm(form);
}
