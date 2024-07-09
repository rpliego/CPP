#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 55), _target("~NoTarget~") 
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Default Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& toCopy) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
	*this = toCopy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& toCopy)
{
	std::cout << "RobotomyRequestForm = overload called" << std::endl;

	this->_target = toCopy._target;
	if (toCopy.getBoolSigned() == true)
		this->setSigned();

	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm Parametized Constructor called" << std::endl;
	this->_target = target;
}

void	RobotomyRequestForm::executeForm() const
{
	std::cout << "* Some drilling noises *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << "'s robotimization has failed" << std::endl;
}