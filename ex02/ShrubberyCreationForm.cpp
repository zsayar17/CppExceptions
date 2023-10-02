#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137, target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getSignGrade(), other.getExecGrade(), other.getTarget()){
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	setIsSigned(other.getIsSigned());
	setTarget(other.getTarget());
	return (*this);
}

const char* ShrubberyCreationForm::FileFailure::what() const throw() {
	return ("Error opening file");
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	static const char *tree = "    ^\n   ^^^\n  ^^^^^\n ^^^^^^^\n^^^^^^^^^\n    |\n";

	checkExec(executor);
	std::ofstream newfile((getTarget() + "_shrubbery").c_str());
	if (!newfile.is_open()) throw(FileFailure());
	newfile << tree;
	newfile.close();
}
