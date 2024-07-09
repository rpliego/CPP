#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& toCopy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& toCopy);

		PresidentialPardonForm(std::string target);

		void	executeForm() const;
};


#endif