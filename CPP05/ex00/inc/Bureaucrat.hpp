#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>


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
		void		setGrade(const int newGrade);

		void		incrementGrade(const int i);
		void		decrementGrade(const int i);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
                {
                    return ("Error: Grade is too low.");
                }
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
                {
                    return ("Error: Grade is too low.");
                }
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif