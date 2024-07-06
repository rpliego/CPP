#include <AForm.hpp>

AForm::AForm() : _name("default"), _signed(0), _grdToSign(150), _grdToExecute(150)
{
	std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::~AForm() {std::cout << "AForm Default Destructor called" << std::endl;}

AForm::AForm(const AForm& toCopy)
{
	std::cout << "AForm Copy Constructor called" << std::endl;
	*this = toCopy;
}

AForm& AForm::operator=(const AForm& toCopy)
{
	std::cout << "AForm = overload called" << std::endl;

	this->_signed = toCopy._signed;
	this->_grdToSign = toCopy._grdToSign;
	this->_grdToExecute = toCopy._grdToExecute;

	return *this;
}

AForm::AForm(std::string name, const int toSign, const int toExecute) : _name(name), _signed(0)
{
	std::cout << "AForm Parametized Constructor called" << std::endl;
	this->_grdToSign = 150;
	this->_grdToExecute = 150;
	try
	{
		if (toSign < 1 || toExecute < 1)
			throw AForm::GradeTooHighException();
		else if (toSign > 150 || toExecute > 150)
			throw AForm::GradeTooLowException();
		this->_grdToSign = toSign;
		this->_grdToExecute = toExecute;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << this->_name <<" grades set to 150" << std::endl;
	}
}


std::string	AForm::getName() const {return this->_name;}

bool		AForm::getBoolSigned() const {return this->_signed;}

int			AForm::getGradeToSign() const {return this->_grdToSign;}

int			AForm::getGradeToExecute() const {return this->_grdToExecute;}

void		AForm::setSigned() {this->_signed = 1;}

void		AForm::beSigned(const Bureaucrat& b)
{
	if (this->_signed == 1)
		throw AlreadySigned();
	//b.signForm(*this);
	this->_signed = 1;
	std::cout << "Bureaucrat " << b.getName() << " signed " << this->getName() << std::endl;
}


void	AForm::execute(const Bureaucrat& executor) const
{
	try
	{
		if (this->_signed == false)
			throw AlreadySigned();
		else if(this->_grdToExecute < executor.getGrade())
			throw Bureaucrat::GradeTooLowException();
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	executeForm();
}


std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm:" << f.getName() << ", Signed:" << f.getBoolSigned() 
	<< ", Grade to sign:" << f.getGradeToSign() << ", Grade to execute:" 
	<< f.getGradeToExecute();

	return os;
}