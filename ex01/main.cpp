#include "Bureaucrat.hpp"
#include "Form.hpp"

//formlar tekrar imzalanabilir mi?
int main()
{
	// Create Form
	try
	{
		Form form("paper", -1, 1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Form form("paper", 151, 1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	Form form("paper", 32, 32);
	Form form1 = form;

	std::cout << form << "\n" << form1 << std::endl << std::endl;

	Bureaucrat bureaucrat("ahmet", 32);

	bureaucrat.signForm(form);
	bureaucrat.decrement();
	bureaucrat.signForm(form1);
	bureaucrat.increment();
	bureaucrat.signForm(form1);
	bureaucrat.signForm(form1);
	std::cout << form << "\n" << form1 << std::endl;
}
