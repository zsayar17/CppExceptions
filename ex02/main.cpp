#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void createRandomForms(AForm **forms, int formcount)
{
	int randomnumber;


	while (formcount--)
	{
		randomnumber = std::rand() % 3;
		if (randomnumber == 0) *forms = new ShrubberyCreationForm("shruberry");
		else if (randomnumber == 1) *forms = new PresidentialPardonForm("presidential");
		else *forms = new RobotomyRequestForm("robotomy");
		forms++;
	}
}

void deleteForms(AForm **forms)
{
	AForm **tempforms;

	tempforms = forms;
	--forms;
	while (*(++forms)) delete *forms;
	delete[] tempforms;
}


int main()
{
	std::srand(std::time(nullptr));
	Bureaucrat ahmet("ahmet", 138);
	Bureaucrat mehmet("mehmet", 1);


	//execute Shruberry
	std::cout << "\n--EXECUTE SHRUBERRY--\n" << std::endl;
	{
		Bureaucrat newbureaucrat("Adam", 138);
		ShrubberyCreationForm form("target");
		newbureaucrat.executeForm(form);
		newbureaucrat.signForm(form);
		newbureaucrat.executeForm(form);
		newbureaucrat.increment();
		newbureaucrat.executeForm(form);
		newbureaucrat.executeForm(form);
	}
	//execute Robotomy
	std::cout << "\n--EXECUTE ROBOTOMY--\n" << std::endl;
	{
		Bureaucrat newbureaucrat("Adam", 46);
		RobotomyRequestForm form("target");
		newbureaucrat.executeForm(form);
		newbureaucrat.signForm(form);
		newbureaucrat.executeForm(form);
		newbureaucrat.increment();
		newbureaucrat.executeForm(form);
		newbureaucrat.executeForm(form);
	}
	//execute Presidential
	std::cout << "\n--EXECUTE PRESIDENTIAL--\n" << std::endl;
	{
		Bureaucrat newbureaucrat("Adam", 6);
		PresidentialPardonForm form("target");
		newbureaucrat.executeForm(form);
		newbureaucrat.signForm(form);
		newbureaucrat.executeForm(form);
		newbureaucrat.increment();
		newbureaucrat.executeForm(form);
		newbureaucrat.executeForm(form);
	}
	//random execute test
	std::cout << "\n--RANDOM EXECUTE TEST--\n" << std::endl;
	{
		int		formcount = 10;
		AForm **forms = new AForm*[formcount + 1];
		forms[formcount] = NULL;
		createRandomForms(forms, formcount);
		for (int i = 0; i < formcount; i++) ahmet.signForm(*(forms[i]));
		std::cout << std::endl;
		for (int i = 0; i < formcount; i++) std::cout << i + 1 << ": " <<  *forms[i] << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < formcount; i++) ahmet.executeForm(*forms[i]);
		std::cout << std::endl;
		for (int i = 0; i < formcount; i++) mehmet.executeForm(*forms[i]);
		std::cout << std::endl;
		for (int i = 0; i < formcount; i++) mehmet.signForm(*(forms[i]));
		std::cout << std::endl;
		for (int i = 0; i < formcount; i++) mehmet.executeForm(*forms[i]);
		deleteForms(forms);
	}
}

