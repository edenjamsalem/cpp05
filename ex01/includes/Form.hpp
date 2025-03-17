#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Beaurocrat.hpp"

class Beaurocrat; 

class Form
{
	private:
		const std::string _name;
		bool _signed;
		int	_signed_grade;
		int	_execute_grade;


	public:
		Form();
		Form(std::string name, int s_grade, int e_grade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string getName() const;
		bool getIsSigned() const;
		int getSignedGrade() const;
		int getExecuteGrade() const;
		void beSigned(Beaurocrat &beaurocrat);

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

std::ostream &operator <<(std::ostream &os, Form &form);

#endif
