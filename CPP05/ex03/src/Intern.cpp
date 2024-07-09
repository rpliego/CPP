#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

typedef AForm* (*ptrarray)(std::string);

Intern::Intern(){std::cout << "Intern Default Constructor called" << std::endl;}

Intern::~Intern() {std::cout << "Intern Default Destructor called" << std::endl;}

Intern::Intern(const Intern& toCopy) {(void)toCopy;}

Intern& Intern::operator=(const Intern& toCopy)
{
	(void)toCopy;
	return *this;
}

AForm*	makePresindentialPardon(std::string target)
{
	std::cout << "Intern creates PresidentialPardon"<< std::endl;
	return new PresidentialPardonForm(target);
}

AForm*	makeShrubberyCreation(std::string target)
{
	std::cout << "Intern creates ShrubberyCreation"<< std::endl;
	return new ShrubberyCreationForm(target);
}

AForm*	makeRobotomyRequest(std::string target)
{
	std::cout << "Intern createsRobotomyRequest"<< std::endl;
	return new RobotomyRequestForm(target);
}


AForm*	Intern::makeForm(std::string nameForm, std::string nameTarget) const
{
	ptrarray functions[3] = { makePresindentialPardon, makeShrubberyCreation, makeRobotomyRequest };
	std::string	aux[3] = {"presidential pardon", "shrubbery creation", "robotomy request"};

	for (int i = 0; i < 3; i++)
	{
		if (nameForm == aux[i])
		{
			return functions[i](nameTarget);
		}
	}
	//throw DontExist();
	std::cout << "Intern could not create the Form"<< std::endl;
	return NULL;
}


