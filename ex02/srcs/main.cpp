#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
	srand(time(0));

	Bureaucrat eden("Eden", 1);
	Bureaucrat john("John", 150);
	ShrubberyCreationForm tree("autumn");
	RobotomyRequestForm robot("IRobot");
	PresidentialPardonForm pardon("Andrew Tate");

	std::cout << eden;
	std::cout << john;
	std::cout << "\n";

	john.signForm(tree);
	john.signForm(robot);
	john.signForm(pardon);

	std::cout << "\n";

	eden.executeForm(tree);
	eden.executeForm(robot);
	eden.executeForm(pardon);

	std::cout << "\n";

	eden.signForm(tree);
	eden.signForm(robot);
	eden.signForm(pardon);

	std::cout << "\n";

	john.executeForm(tree);
	john.executeForm(robot);
	john.executeForm(pardon);
	
	std::cout << "\n";

	eden.executeForm(tree);
	std::cout << "\n";

	eden.executeForm(robot);
	std::cout << "\n";

	eden.executeForm(pardon);
	std::cout << "\n";

}
