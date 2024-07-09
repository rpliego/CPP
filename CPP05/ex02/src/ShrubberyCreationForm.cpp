#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("~NoTarget~") 
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

void	ShrubberyCreationForm::executeForm() const
{
	std::ofstream file;

	file.open((this->_target + "_shrubbery").c_str());

	if (file.is_open() == false)
	{
		std::cout << "Error creating the file" << std::endl;
		return ;
	}
	std::cout << "The ASCII trees have been created" << std::endl;

	file << std::endl;
    file << "                @@@@@@@," << std::endl;
    file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    file << "       |o|        | |         | |" << std::endl;
    file << "       |.|        | |         | |" << std::endl;
    file << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
    file.close();
}