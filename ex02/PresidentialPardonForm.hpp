#ifndef __PRESIDENTIALPARDONFORM__HPP__
# define __PRESIDENTIALPARDONFORM__HPP__

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		void execute(Bureaucrat const & executor) const;

};


#endif
