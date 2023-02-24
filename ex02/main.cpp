#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac < 1)
			return 0;
		PmergeMe test;
		test.ft_sort(av);
	}
 	catch(const std::exception& e)
 	{
 		std::cerr << e.what() << '\n';
 	}
}
