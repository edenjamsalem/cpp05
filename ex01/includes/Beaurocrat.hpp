#ifndef BEAUROCRAT_HPP
#define BEAUROCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form; 

class Beaurocrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Beaurocrat();
		Beaurocrat(std::string name, int grade);
		Beaurocrat(const Beaurocrat& other);
		Beaurocrat& operator=(const Beaurocrat& other);
		~Beaurocrat();

		const std::string	getName() const;
		int					getGrade();
		void				setGrade(int grade);
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form &form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

std::ostream &operator <<(std::ostream &os, Beaurocrat &beaurocrat);

#endif
