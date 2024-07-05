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
	this->_grade = 150;
	if (i < 1)
	{
		std::cout << name <<"Grade set to 150" << std::endl;
		throw GradeTooHighException();
	}
	else if(i > 150)
	{
		std::cout << name <<" grade set to 150" << std::endl;
		throw GradeTooLowException();
	}
	else
		this->_grade = i;
}


std::string	Bureaucrat::getName() const {return this->_name;}

int			Bureaucrat::getGrade() const {return this->_grade;}

void		Bureaucrat::setGrade(const int newGrade) {this->_grade = newGrade;}

void		Bureaucrat::incrementGrade(const int i)
{
	try
	{
		if (this->_grade - i < 1)
			throw GradeTooHighException();
		this->_grade -= i;
	}
	catch(const std::exception& e)
	{
		this->_grade = 1;
		std::cerr << e.what() << '\n';
		std::cout << this->_name <<" grade set to 1" << std::endl;
	}
}

void		Bureaucrat::decrementGrade(const int i) 
{
	try
	{
		if (this->_grade + i < 1)
			throw GradeTooLowException();
		this->_grade += i;
	}
	catch(const std::exception& e)
	{
		this->_grade = 150;
		std::cerr << e.what() << '\n';
		std::cout << this->_name <<" grade set to 150" << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();

	return os;
}