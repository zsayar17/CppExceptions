#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm() {

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), other.getSignGrade(), other.getExecGrade(), other.getTarget()){
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	setIsSigned(other.getIsSigned());
	setTarget(other.getTarget());
	return (*this);
}

const char *RobotomyRequestForm::RobotomyFailure::what() const throw() {
	return ("Robotomy failure");
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	checkExec(executor);
	std::cout << "zrrrrrrrrrrrrr trrrrrrrrrr krrrrrrrrrr\n";
	if (std::rand() % 2) throw(RobotomyFailure());
	std::cout << getTarget() << " has been robotomized" << std::endl;
}
