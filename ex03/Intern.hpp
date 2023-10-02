#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef AForm* (*functionptr)(std::string);

class Intern
{
	private:
		static const functionptr functions[3];

		static AForm* createShruberry(std::string target);
		static AForm* createRobotomy(std::string target);
		static AForm* createPresidential(std::string target);

	public:
		static const std::string names[3];
		enum {
			SHRUBERRY, ROBOTOMY, PRESIDENTIAL
		};

		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* makeForm(std::string name, std::string target);

		class NoMatchName : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};


#endif
