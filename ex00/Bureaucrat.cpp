#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"){
	setGrade(LOWEST_GRADE);
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.getName()) {
	*this = other;
}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat& 	Bureaucrat::operator=(const Bureaucrat& other) {
	setGrade(other.getGrade());
	return (*this);
}

int	Bureaucrat::getGrade() const {
	return (this->grade);
}

std::string	Bureaucrat::getName() const {
	return (this->name);
}

void	Bureaucrat::increment() {
	setGrade(getGrade() - 1);
}

void	Bureaucrat::decrement() {
	setGrade(getGrade() + 1);
}

void	Bureaucrat::setGrade(int new_grade) {
	if (new_grade > LOWEST_GRADE) throw (Bureaucrat::GradeTooLowException());
	else if (new_grade < HIGHEST_GRADE) throw (Bureaucrat::GradeTooHighException());
	else this->grade = new_grade;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade can not be lower than 150!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade can not be over than 1!");
}

std::ostream& operator<<(std::ostream& ostrm, Bureaucrat& bureaucrat) {
	return (ostrm << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}

