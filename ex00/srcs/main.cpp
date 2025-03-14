#include "../includes/Beaurocrat.hpp"

int main()
{
	Beaurocrat eden;
	Beaurocrat john("John", 125);
	Beaurocrat harry(john);

	std::cout << eden;
	std::cout << john;
	std::cout << harry;
}
