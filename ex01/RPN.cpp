#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(char *str) : str_(str){}

RPN::~RPN(){}

RPN::RPN(const RPN & origin)
{
	*this = origin; 
}

RPN & RPN::operator=(const RPN & origin)
{
	this->str_ = origin.str_;
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
		if (c == '-')
			pile_.push(operator1 - operator2);
		if (c == '*')
			pile_.push(operator1 * operator2);
		if (c == '/')
			pile_.push(operator1 / operator2);
	}
	else
		throw "calcul impossible";
}

int	RPN::calcul()
{
	int i = 0;
	while(str_[i])
	{
		if (isdigit(str_[i]))
			pile_.push(str_[i] - '0');
		else
			operation(str_[i]);
		i++;
	}
	if (pile_.size() == 1)
		return pile_.top();
	else
		throw "calcul impossible";
}