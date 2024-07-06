#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <Bureaucrat.hpp>

class Bureaucrat;

class AForm
{
	private:
		const std::string 	_name;
		bool				_signed;
		int					_grdToSign;
		int					_grdToExecute;
	
	public:
		AForm();
		~AForm();
		AForm(const AForm& toCopy);
		AForm& operator=(const AForm& toCopy);

		AForm(std::string name, const int toSign, const int toExecute);

		std::string		getName() const;
		bool			getBoolSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;

		void			setSigned();

		void			beSigned(const Bureaucrat& b);

		void			execute(Bureaucrat const & executor) const; 
		virtual void	executeForm() const = 0;

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

		class NotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form Error: Not signed");
				}
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif