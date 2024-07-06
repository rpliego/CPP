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

	if (i > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (i < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = i;
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

void		Bureaucrat::signForm(AForm& toSing) const
{
	if (this->_grade > toSing.getGradeToSign())
		throw GradeTooLowException();
	toSing.beSigned(*this);
}

void		Bureaucrat::executeForm(const AForm& form)
{
	try
	{
		if (this->getGrade() > form.getGradeToExecute())
			throw GradeTooLowException();
		else if (form.getBoolSigned() == true)
			throw AForm::NotSigned();
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();

	return os;
}