#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
	private:
		

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		void	formCreateMessage(std::string &form);
		AForm *makeForm(std::string name, std::string target);	
};

#endif
