#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

		//Setter
		void			setGrade(int new_grade);
	public:
		enum {
			LOWEST_GRADE = 150, HIGHEST_GRADE = 1
		};
		//Orthadox form
						Bureaucrat();
						Bureaucrat(const std::string name, int grade);
						Bureaucrat(const Bureaucrat& other);
						~Bureaucrat();
		Bureaucrat& 	operator=(const Bureaucrat& other);

		//Getters
		int				getGrade() const;
		std::string		getName() const;

		//Others
		void			increment();
		void			decrement();
		void 			signForm(AForm& form);
		void			executeForm(AForm const& form);

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

std::ostream& operator<<(std::ostream& ostrm, Bureaucrat& bureaucrat);

#endif
