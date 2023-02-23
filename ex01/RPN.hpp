#ifndef RPN_H
# define RPN_H

#include <stack>
#include <cctype>
#include <iostream>

class RPN
{
private:
	std::stack<int> pile_;
	char *str_;
public:
	RPN();
	RPN(char *str);
	RPN(const RPN & origin);
	RPN & operator=(const RPN & origin);
	~RPN();

	int	calcul();
	void operation(char c);
};

#endif
