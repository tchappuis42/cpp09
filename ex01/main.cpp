#include "RPN.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw "error";

		RPN rpn;
		std::cout << rpn.calcul(av[1]) << std::endl;
	}
 	catch(const char *msg)
 	{
 		std::cerr << msg << '\n';
 	}
}
