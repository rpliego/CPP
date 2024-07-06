#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& toCopy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& toCopy);

		RobotomyRequestForm(std::string target);

		void	executeForm();
};


#endif