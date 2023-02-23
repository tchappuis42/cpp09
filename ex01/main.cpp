#include "RPN.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::exception();

		RPN rpn;
		std::cout << rpn.calcul(av[1]) << std::endl;
	}
 	catch(const std::exception& e)
 	{
 		std::cerr << e.what() << '\n';
 	}
}