#ifndef __SHRUBBERYCREATIONFORM__HPP__
# define __SHRUBBERYCREATIONFORM__HPP__

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		void execute(Bureaucrat const & executor) const;

		class FileFailure : public std::exception
		{
			public:
				const char*	what() const throw();
		};

};


#endif
