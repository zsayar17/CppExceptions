#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), sign_grade(Bureaucrat::LOWEST_GRADE), exec_grade(Bureaucrat::LOWEST_GRADE) {
	setIsSigned(false);
	setTarget("default");
}

AForm::AForm(std::string name, int sign_grade, int exec_grade, std::string target) : name(name), sign_grade(sign_grade), exec_grade(exec_grade) {
	if (getExecGrade() > Bureaucrat::LOWEST_GRADE || getSignGrade() > Bureaucrat::LOWEST_GRADE)
		throw (AForm::GradeTooLowException());
	else if (getExecGrade() < Bureaucrat::HIGHEST_GRADE || getSignGrade() < Bureaucrat::HIGHEST_GRADE)
		throw (AForm::GradeTooHighException());
	setIsSigned(false);
	setTarget(target);
}

AForm::AForm(const AForm& other) : name(other.getName()), sign_grade(other.getSignGrade()), exec_grade(other.getExecGrade()) {
	*this = other;
}

AForm& AForm::operator=(const AForm& other) {
	setIsSigned(other.getIsSigned());
	setTarget(other.getTarget());
	return (*this);
}

AForm::~AForm() {

}

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (getSignGrade() < bureaucrat.getGrade()) throw(AForm::GradeTooLowException());
	setIsSigned(true);
}

void AForm::checkExec(const Bureaucrat& bureaucrat) const {
	if (!getIsSigned()) throw(FormNotSigned());
	else if (bureaucrat.getGrade() > getExecGrade()) throw(GradeTooLowException());
}


int AForm::getSignGrade() const {
	return (this->sign_grade);
}

int AForm::getExecGrade() const {
	return (this->exec_grade);
}

std::string AForm::getName() const {
	return (this->name);
}

bool AForm::getIsSigned() const {
	return (this->is_signed);
}

void AForm::setIsSigned(bool newvalue) {
	is_signed = newvalue;
}

std::string AForm::getTarget() const {
	return (this->target);
}

void AForm::setTarget(std::string target) {
	this->target = target;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char* AForm::FormNotSigned::what() const throw() {
	return ("Form is not signed yet");
}

std::ostream& operator<<(std::ostream& ostrm, AForm& form) {
	return (ostrm << "form name is: " << form.getName() << ", form sign grade is: " << form.getSignGrade()
	 		<< ", form exec grade is: " << form.getExecGrade() << ", form sign situation is: " << form.getIsSigned());
}
