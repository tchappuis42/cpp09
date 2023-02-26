#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	std::queue<BitcoinExchange> bit;
	std::ifstream configfile(av[1]);
	std::string read;

	while(getline(configfile, read))
		bit.push(BitcoinExchange(read));

	while(!bit.empty())
	{
		bit.front().pushInfo();
		bit.pop();
	}
}