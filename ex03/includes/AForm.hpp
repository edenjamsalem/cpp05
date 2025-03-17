#ifndef FORM_HPP
#define FORM_HPP

#include <iostream> 
#include <fstream> 
#include <exception>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"

class Bureaucrat; 

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		int	_signed_grade;
		int	_execute_grade;

	public:
		AForm();
		AForm(std::string name, int s_grade, int e_grade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string getName() const;
		bool getIsSigned() const;
		void setIsSigned(bool isSigned);
		int getSignedGrade() const;
		int getExecuteGrade() const;
		void beSigned(Bureaucrat &bureaucrat);
		void execute(Bureaucrat const & executor) const;
		
		virtual	void execute_action() const = 0;

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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
};

std::ostream &operator <<(std::ostream &os, AForm &form);

#endif
