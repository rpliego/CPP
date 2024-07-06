#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :_target("~NoTarget~"), AForm("ShrubberyCreationForm", 145, 137) 
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Default Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& toCopy) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
	*this = toCopy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& toCopy)
{
	std::cout << "ShrubberyCreationForm = overload called" << std::endl;

	this->_target = toCopy._target;
	if (toCopy.getBoolSigned() == true)
		this->setSigned();

	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm Parametized Constructor called" << std::endl;
	this->_target = target;
}

void	ShrubberyCreationForm::executeForm()
{
	
}