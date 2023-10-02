#include "Intern.hpp"

const std::string Intern::names[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
const functionptr Intern::functions[3] = {Intern::createShruberry, Intern::createRobotomy, Intern::createPresidential};

Intern::Intern() {

}

Intern::~Intern() {

}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return (*this);
}

AForm* Intern::createPresidential(std::string target) {
	std::cout << "Intern created Presidential Form" << std::endl;
	return (new PresidentialPardonForm(target));
}

AForm* Intern::createRobotomy(std::string target) {
	std::cout << "Intern created Robotomy Form" << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createShruberry(std::string target) {
	std::cout << "Intern created Shruberry Form" << std::endl;
	return (new ShrubberyCreationForm(target));
}

const char* Intern::NoMatchName::what() const throw() {
	return ("Name, does not match with any name between what I have");
}

AForm* Intern::makeForm(std::string name, std::string target) {
	try
	{
		for (int i = 0; i < (int)names->length(); i++)
			if (!name.compare(names[i])) return (functions[i](target));
		throw(NoMatchName());
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return (NULL);
	}



}
