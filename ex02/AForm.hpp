#ifndef __AFORM_HPP__
# define __AFORM_HPP__

#include <iostream>
#include <ctime>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	const int	sign_grade;
	const int	exec_grade;
	bool		is_signed;
	std::string target;
public:
	AForm();
	AForm(std::string name, int sign_grade, int exec_grade, std::string target);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	//getter
	int			getSignGrade()	const;
	int			getExecGrade()	const;
	std::string	getName()		const;
	std::string getTarget()		const;
	bool		getIsSigned()	const;

	//setter
	void setIsSigned(bool new_value);
	void setTarget(std::string target);

	//other
	void beSigned(Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
	void checkExec(const Bureaucrat& bureaucrat) const;

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
	class FormNotSigned : public std::exception
	{
		public:
			const char*	what() const throw();
	};
};

std::ostream& operator<<(std::ostream& ostrm, AForm& form);

#endif
