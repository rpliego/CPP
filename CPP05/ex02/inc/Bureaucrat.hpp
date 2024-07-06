#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <AForm.hpp>
#include <stdexcept>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& toCopy);
		Bureaucrat& operator=(const Bureaucrat& toCopy);

		Bureaucrat(std::string name, int i);


		std::string	getName() const;
		int			getGrade() const;

		void		incrementGrade(const int i);
		void		decrementGrade(const int i);

		void		signForm(AForm& toSing) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
                {
                    return ("Bureaucrat Error: Grade is too high.");
                }
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
                {
                    return ("Bureaucrat Error: Grade is too low.");
                }
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif