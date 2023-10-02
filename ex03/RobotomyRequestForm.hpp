#ifndef __ROBOTOMYREQUESTFORM__HPP__
# define __ROBOTOMYREQUESTFORM__HPP__

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		void execute(Bureaucrat const & executor) const;

		class RobotomyFailure : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

#endif
