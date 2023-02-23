#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN & origin)
{
	*this = origin; 
}

RPN & RPN::operator=(const RPN & origin)
{
	this->pile_ = origin.pile_;
	return *this;
}

void RPN::operation(char c)
{
	if (c == ' ')
		return ;
	int operator1;
	int operator2;
	if (pile_.size() > 1)
	{
		operator2 = pile_.top();
		pile_.pop();
		operator1 = pile_.top();
		pile_.pop();
		if (c == '+')
			pile_.push(operator1 + operator2);
		else if (c == '-')
			pile_.push(operator1 - operator2);
		else if (c == '*')
			pile_.push(operator1 * operator2);
		else if (c == '/')
			pile_.push(operator1 / operator2);
		else
			throw std::exception();
	}
	else
		throw std::exception();
}

int	RPN::calcul(char *str)
{
	int i = 0;
	while(str[i])
	{
		if (isdigit(str[i]))
			pile_.push(str[i] - '0');
		else
			operation(str[i]);
		i++;
	}
	if (pile_.size() == 1)
		return pile_.top();
	else
		throw std::exception();
}

void RPN::printstack()
{
	while (!pile_.empty()) 
	{
    	std::cout << pile_.top() << " ";
    	pile_.pop();
	}
	std::cout << std::endl;
}