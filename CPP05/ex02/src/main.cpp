#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
    PresidentialPardonForm a("Joan");
	std::cout << "-------------------------" << std::endl;
    Bureaucrat bob("bob", 1);
	std::cout << "-------------------------" << std::endl;

	RobotomyRequestForm b("Anna");
	std::cout << "-------------------------" << std::endl;
	Bureaucrat di("di", 1);
	std::cout << "-------------------------" << std::endl;
	std::cout << "First try catch" << std::endl;
	std::cout << "-------------------------" << std::endl;
    try
	{
		bob.signForm(a);
		std::cout << "-------------------------" << std::endl;
		bob.executeForm(a);
		std::cout << "-------------------------" << std::endl;
		di.signForm(b);
		std::cout << "-------------------------" << std::endl;
		di.executeForm(b);
		di.executeForm(b);
		di.executeForm(b);
		di.executeForm(b);
		di.executeForm(b);
		di.executeForm(b);
		di.executeForm(b);
		di.executeForm(b);
		di.executeForm(b);
		di.executeForm(b);
		std::cout << "-------------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-------------------------" << std::endl;

    return (0);
}
