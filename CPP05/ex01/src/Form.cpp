#include <Form.hpp>

Form::Form() : _name("default"), _signed(0), _grdToSign(150), _grdToExecute(150)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::~Form() {std::cout << "Form Default Destructor called" << std::endl;}

Form::Form(const Form& toCopy)
{
	std::cout << "Form Copy Constructor called" << std::endl;
	*this = toCopy;
}

Form& Form::operator=(const Form& toCopy)
{
	std::cout << "Form = overload called" << std::endl;

	this->_signed = toCopy._signed;
	this->_grdToSign = toCopy._grdToSign;
	this->_grdToExecute = toCopy._grdToExecute;

	return *this;
}

Form::Form(std::string name, const int toSign, const int toExecute) : _name(name), _signed(0)
{
	std::cout << "Form Parametized Constructor called" << std::endl;
	this->_grdToSign = 150;
	this->_grdToExecute = 150;
	try
	{
		if (toSign < 1 || toExecute < 1)
			throw Form::GradeTooHighException();
		else if (toSign > 150 || toExecute > 150)
			throw Form::GradeTooLowException();
		this->_grdToSign = toSign;
		this->_grdToExecute = toExecute;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << this->_name <<" grades set to 150" << std::endl;
	}
}


std::string	Form::getName() const {return this->_name;}

bool		Form::getBoolSigned() const {return this->_signed;}

int			Form::getGradeToSign() const {return this->_grdToSign;}

int			Form::getGradeToExecute() const {return this->_grdToExecute;}

void		Form::setSigned() {this->_signed = 1;}

void		Form::beSigned(const Bureaucrat& b)
{
	if (this->_signed == 1)
		throw AlreadySigned();
	b.signForm(*this);
	this->_signed = 1;
	std::cout << "Bureaucrat " << b.getName() << " signed " << this->getName() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form:" << f.getName() << ", Signed:" << f.getBoolSigned() 
	<< ", Grade to sign:" << f.getGradeToSign() << ", Grade to execute:" 
	<< f.getGradeToExecute();

	return os;
}