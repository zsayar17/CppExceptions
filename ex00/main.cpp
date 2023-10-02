#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat burecraut("Ahmet", 150);

	//incremant
	try
	{
		for (int i = 0; i < 200; i++) burecraut.increment();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << burecraut << std::endl << std::endl;

	//decremant
	try
	{
		for (int i = 0; i < 200; i++) burecraut.decrement();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << burecraut << std::endl << std::endl;

	//implemant
	try
	{
		Bureaucrat bb("Mehmet", 0);
		std::cout << bb << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Bureaucrat bb("Mehmet", 151);
		std::cout << bb << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Bureaucrat bb("Mehmet", 49);
		std::cout << bb << std::endl;
	}

	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;

	Bureaucrat bb("Mehmet", 39);

	bb = burecraut;
	std::cout << burecraut << std::endl;
	std::cout << bb << std::endl << std::endl;

	Bureaucrat bbb = bb;
	std::cout << bbb << std::endl;
	std::cout << bb << std::endl;
}
