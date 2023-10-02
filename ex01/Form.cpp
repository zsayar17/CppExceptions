#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), sign_grade(Bureaucrat::LOWEST_GRADE), exec_grade(Bureaucrat::LOWEST_GRADE) {
	setIsSigned(false);
}

Form::Form(std::string name, int sign_grade, int exec_grade) : name(name), sign_grade(sign_grade), exec_grade(exec_grade) {
	if (getExecGrade() > Bureaucrat::LOWEST_GRADE || getSignGrade() > Bureaucrat::LOWEST_GRADE)
		throw (Form::GradeTooLowException());
	else if (getExecGrade() < Bureaucrat::HIGHEST_GRADE || getSignGrade() < Bureaucrat::HIGHEST_GRADE)
		throw (Form::GradeTooHighException());
	setIsSigned(false);
}

Form::Form(const Form& other) : name(other.getName()), sign_grade(other.getSignGrade()), exec_grade(other.getExecGrade()) {
	*this = other;
}

Form& Form::operator=(const Form& other) {
	setIsSigned(other.getIsSigned());
	return (*this);
}

Form::~Form() {

}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (getSignGrade() < bureaucrat.getGrade()) throw(Form::GradeTooLowException());
	setIsSigned(true);
}

int Form::getSignGrade() const {
	return (this->sign_grade);
}

int Form::getExecGrade() const {
	return (this->exec_grade);
}

std::string Form::getName() const {
	return (this->name);
}

bool Form::getIsSigned() const {
	return (this->is_signed);
}

void Form::setIsSigned(bool newvalue) {
	is_signed = newvalue;
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

std::ostream& operator<<(std::ostream& ostrm, Form& form) {
	return (ostrm << "form name is: " << form.getName() << ", form sign grade is: " << form.getSignGrade()
	 		<< ", form exec grade is: " << form.getExecGrade() << ", form sign situation is: " << form.getIsSigned());
}
