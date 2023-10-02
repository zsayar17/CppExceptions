#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm() {

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5, target) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), other.getSignGrade(), other.getExecGrade(), other.getTarget()){
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	setIsSigned(other.getIsSigned());
	setTarget(other.getTarget());
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	checkExec(executor);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
