#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

#include <iostream>

class Bureaucrat
{
	private:
		enum {
			LOWEST_GRADE = 150, HIGHEST_GRADE = 1
		};

		const std::string	name;
		int					grade;

		//Setter
		void			setGrade(int new_grade);
	public:
		//Orthadox Form
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
