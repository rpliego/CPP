#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {std::cout << "Bureaucrat Destructor called" << std::endl;}

Bureaucrat::Bureaucrat(const Bureaucrat& toCopy)
{
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
	*this = toCopy;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& toCopy)
{
	std::cout << "Bureaucrat = overload called" << std::endl;
	this->_grade = toCopy._grade;

	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int i) : _name(name)
{
	std::cout << "Bureaucrat Parametized Constructor called" << std::endl;

	this->_grade = i;
	try
	{
		if (i > 150)
			throw GradeTooLowException();
		else if (i < 1)
			throw GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		if (i > 150)
		{
			this->_grade = 150;
			std::cout << this->_name <<" grade set to 150" << std::endl;
		}
		else
		{
			this->_grade = 1;
			std::cout << this->_name <<" grade set to 1" << std::endl;
		}
	}
}


std::string	Bureaucrat::getName() const {return this->_name;}

int			Bureaucrat::getGrade() const {return this->_grade;}

void		Bureaucrat::incrementGrade(const int i)
{
	if (this->_grade - i < 1)
		throw GradeTooHighException();
	this->_grade -= 1;
}

void		Bureaucrat::decrementGrade(const int i) 
{
	if (this->_grade + i > 150)
		throw GradeTooLowException();
	this->_grade += 1;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();

	return os;
}