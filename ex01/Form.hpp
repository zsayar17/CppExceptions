#ifndef __FORM_HPP__
# define __FORM_HPP__

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	const int	sign_grade;
	const int	exec_grade;
	bool		is_signed;

public:
	Form();
	Form(std::string name, int sign_grade, int exec_grade);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	//getter
	int			getSignGrade()	const;
	int			getExecGrade()	const;
	std::string	getName()		const;
	bool		getIsSigned()	const;

	//setter
	void setIsSigned(bool new_value);

	//other
	void beSigned(Bureaucrat& bureaucrat);

	//Classes
	class GradeTooHighException : public std::exception
	{
		//late binding -> dynamic binding
		public:
			const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char*	what() const throw();
	};
};

std::ostream& operator<<(std::ostream& ostrm, Form& form);

#endif
