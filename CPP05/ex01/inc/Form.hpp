#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <Bureaucrat.hpp>

class Bureaucrat;

class Form
{
	private:
		const std::string 	_name;
		bool				_signed;
		int					_grdToSign;
		int					_grdToExecute;
	
	public:
		Form();
		~Form();
		Form(const Form& toCopy);
		Form& operator=(const Form& toCopy);

		Form(std::string name, const int toSign, const int toExecute);

		std::string	getName() const;
		bool		getBoolSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void		setSigned();

		void		beSigned(const Bureaucrat& b);


		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
                {
                    return ("Form Error: Grade is too high.");
                }
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
                {
                    return ("Form Error: Grade is too low.");
                }
		};

		class AlreadySigned : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form Error: Already signed");
				}
		};
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif