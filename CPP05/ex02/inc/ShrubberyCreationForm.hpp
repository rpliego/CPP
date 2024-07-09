#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& toCopy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& toCopy);

		ShrubberyCreationForm(std::string target);

		void	executeForm() const;
};


#endif