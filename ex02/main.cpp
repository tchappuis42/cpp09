#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac < 2)
			throw "Error: not the right number of arguments.";
		PmergeMe test;
		test.ft_sort(av);
	}
 	catch(const char *str)
 	{
 		std::cerr << str << '\n';
 	}
}
