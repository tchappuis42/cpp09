#include "RPN.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw "pas le bon nombre d'argument";

		RPN rpn(av[1]);
		std::cout << rpn.calcul() << std::endl;
	}
	catch(const char *error)
	{
		std::cout << error << std::endl;
	}
}