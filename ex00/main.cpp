#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange bit;

	if(ac < 1)
		return 0;
	bit.init_csv();
	bit.Bitcoin(av[1]);
}
