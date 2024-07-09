#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& toCopy);
		Intern& operator=(const Intern& toCopy);

		AForm*	makeForm(std::string nameForm, std::string nameTarget) const;

		// class DontExist : public std::exception
		// {
		// 	public:
		// 		virtual const char* what() const throw()
        //         {
        //             return ("Intern Error: Form name doesn't exist");
        //         }
		// };
};


#endif