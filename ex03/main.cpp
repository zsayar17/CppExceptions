#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"



int main()
{
	std::srand(std::time(nullptr));
	Bureaucrat ahmet("ahmet", 138);
	Bureaucrat mehmet("mehmet", 1);

	Intern intern;
	AForm *formptr;



	formptr = intern.makeForm(Intern::names[Intern::SHRUBERRY], "target1");
	std::cout << *formptr << std::endl;
	mehmet.signForm(*formptr);
	mehmet.executeForm(*formptr);
	delete formptr;
	std::cout << std::endl;

	formptr = intern.makeForm(Intern::names[Intern::ROBOTOMY], "target2");
	std::cout << *formptr << std::endl;
	mehmet.signForm(*formptr);
	mehmet.executeForm(*formptr);
	delete formptr;
	std::cout << std::endl;

	formptr = intern.makeForm(Intern::names[Intern::PRESIDENTIAL], "target3");
	std::cout << *formptr << std::endl;
	mehmet.signForm(*formptr);
	mehmet.executeForm(*formptr);
	delete formptr;
	std::cout << std::endl;

	formptr = intern.makeForm("asdsadas", "target4");
	std::cout << formptr << std::endl;
}

