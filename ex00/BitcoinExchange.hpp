#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, float> _map;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange & origin);
	BitcoinExchange & operator=(const BitcoinExchange & origin);
	~BitcoinExchange();

	void	init_csv();
	void	Bitcoin(char *file);
	void	CheckInfo(std::string info);

	bool checkDate(const std::string & str);
	bool checkValue(const std::string & str);

	void	printBit(std::string date, float nb);

	float	GetBitValue(std::string date);
};

#endif
