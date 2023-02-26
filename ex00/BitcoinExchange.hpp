#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <queue>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class BitcoinExchange
{
private:
	std::string str_;
public:
	BitcoinExchange();
	BitcoinExchange(const std::string & str);
	~BitcoinExchange();

	const  std::string	printQueue() const;
	void	pushInfo();

	bool checkDate(const std::string & str);
	bool checkValue(const std::string & str);
};

#endif

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string & str) : str_(str) {}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::pushInfo()
{
	std::string date, s;
	double	value;
	std::istringstream ss(str_);
	int i = 0;

	while (std::getline(ss, s, ' '))
    {
        if (i == 0)
		{
			if (!checkDate(s))
				return ;
			date = s;
		}
		if (i == 1 && s != "|")
		{
			std::cout << "Error: bad input => " << str_ << std::endl;
			return ;
		}
		if (i == 2)
		{
			if (!checkValue(s))
				return ;
			std::istringstream(s) >> value;
		}
		i++;
	}

	if (i != 3)
	{
			std::cout << "Error: bad input => " << str_ << std::endl;
			return ;
	}
	std::cout << "date = " << date << " value = "  << value << std::endl;
	//combien de space si pas bon print error
	//chek le | si pas bon error
	//chek date
	//chek num
	//si tout ok print msg = calcul (fonction)

	
}

const std::string BitcoinExchange::printQueue() const
{
	return str_;
}

bool BitcoinExchange::checkDate(const std::string & str)
{
	if (str.back() == '-')
	{
		std::cout << "Error: .\n";
		return false;	
	}
	std::string s;
	int	year, month, day;
	std::istringstream ss(str);
	int i = 0;
	while (std::getline(ss, s, '-'))
	{
		if (i == 0)
		{
			std::istringstream(s) >> year;
			if (year < 2010 || year > 2022)
			{
				std::cout << "Error: incorrect year.\n";
				return false;
			}
		}
		if (i == 1)
		{
			std::istringstream(s) >> month;
			if (month < 1 || month > 12)
			{
				std::cout << "Error: incorrect month.\n";
				return false;
			}
		}
		if (i == 2)
		{
			std::istringstream(s) >> day;
			if (day < 1 || day > 31)
			{
				std::cout << "Error: incorrect day.\n";
				return false;
			}
			if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
			{
				std::cout << "Error: incorrect day.\n";
				return false;
			}
			if (day > 28 && month == 2)
			{
				std::cout << "Error: incorrect day.\n";
				return false;
			}
		}
		i++;
	}
	if (i != 3)
	{
		std::cout << "Error: date incorect\n";
		return false;
	}
	return true;
}

bool	is_Num(const std::string &str)
{
	if (!str.empty() && str.find_first_not_of("0123456789.-") != std::string::npos)
		return false;
	return true;
}

bool BitcoinExchange::checkValue(const std::string & str)
{
	if (!is_Num(str) || !str.find('.', 0) || str.back() == '.')
	{
		std::cout << "Error: not a Number\n";
		return false; 
	}
	if (str < "0")
	{
		std::cout << "Error: not a positive number.\n";
		return false;
	}
	if (str.length() > 11 || (str.length() == 10 && str > "2147483647"))
	{
		std::cout << "Error: too large a number.\n";
		return false;
	}
	return true;
}
