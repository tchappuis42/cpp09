#ifndef RPN_H
# define RPN_H

#include <stack>
#include <cctype>
#include <iostream>

class RPN
{
private:
	std::stack<int> pile_;
public:
	RPN();
	RPN(const RPN & origin);
	RPN & operator=(const RPN & origin);
	~RPN();

	int	calcul(char *str);
	void operation(char c);
	void printstack();
};

#endif
