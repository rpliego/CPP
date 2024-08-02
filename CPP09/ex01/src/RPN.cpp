#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& toCopy) {(void)toCopy;}

RPN& RPN::operator=(const RPN& toCopy) {(void)toCopy; return *this;}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


void	doOperation(std::stack<int>& stack, char token)
{
	if (stack.size() < 2)
		throw std::logic_error("Error: There are not enough numbers");

	int result;
	int num1 = stack.top();
	stack.pop();
	int num2 = stack.top();
	stack.pop();

	switch (token)
	{
		case '+':
			result = num2 + num1;
			break;
		
		case '-':
			result = num2 - num1;
			break;

		case '/':
			if (num2 == 0)
				throw std::logic_error("Error: Division by 0");
			result = num2 / num1;
			break;

		case '*':
			result = num2 * num1;
			break;
	}

	stack.push(result);
}

void	RPN::RPNcalculator(std::string input)
{
	std::stack<int>	stack;
	std::istringstream	iss(input);
	std::string			token;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "/" || token == "*")
			doOperation(stack, token[0]);
		else
		{
			int value = std::atoi(token.c_str());
			stack.push(value);
		}
	}
	
	if (stack.size() != 1)
		throw std::logic_error("Error: Need more operators");

	std::cout << stack.top() << std::endl;
}