#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <exception>
# include <sstream>
# include <stack>
# include <stdlib.h>


class RPN
{
	public:
		static void RPNcalculator(std::string input);

	private:
		RPN();
		~RPN();
		RPN(const RPN& toCopy);
		RPN& operator=(const RPN& toCopy);
};


#endif