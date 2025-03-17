#include "../includes/Beaurocrat.hpp"

int main()
{
	Beaurocrat eden;
	Beaurocrat john("John", 1);
	Beaurocrat harry(john);

	std::cout << eden;
	std::cout << john;
	std::cout << harry;


	try
	{
		eden.setGrade(151);
	}
	catch (const std::exception &err)
	{
		std::cerr << err.what();
	}
	try
	{
		eden.setGrade(-1);
	}
	catch (const std::exception &err)
	{
		std::cerr << err.what();
	}
	eden.setGrade(150);
	try
	{
		eden.decrementGrade();
	}
	catch (const std::exception &err)
	{
		std::cerr << err.what();
	}

	try
	{
		harry.incrementGrade();
	}
	catch (const std::exception &err)
	{
		std::cerr << err.what();
	}
}
