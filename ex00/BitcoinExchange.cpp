#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::init_csv()
{
	std::ifstream csv("data.csv");
	std::string read;
	float nb;
	size_t size;

	while(getline(csv, read))
 	{
		if (read != "date,exchange_rate")
		{
			size = read.find(',');
			std::istringstream(read.substr(size + 1, read.length())) >> nb;
			_map[read.substr(0, size)] = nb;
		}
	}
}

void	BitcoinExchange::Bitcoin(char *file)
{
 	std::ifstream configfile(file);
	std::string read;

	while(getline(configfile, read))
		CheckInfo(read);
}

void	BitcoinExchange::CheckInfo(std::string info)
{
	std::string date, s;
	float	value;
	std::istringstream ss(info);
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
			std::cout << "Error: bad input => " << info << std::endl;
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
			std::cout << "Error: bad input => " << info << std::endl;
			return ;
	}
	printBit(date, value);
}

bool BitcoinExchange::checkDate(const std::string & str)
{
	if (str.find('-', str.length() - 1) != std::string::npos)
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
	if (!is_Num(str) || !str.find('.', 0) || str.find('.', str.length() - 1) != std::string::npos)
	{
		std::cout << "Error: not a Number\n";
		return false; 
	}
	if (str < "0")
	{
		std::cout << "Error: not a positive number.\n";
		return false;
	}
	if (str.length() > 4 || (str.length() == 4 && str > "1000"))
	{
		std::cout << "Error: too large a number.\n";
		return false;
	}
	return true;
}

void	BitcoinExchange::printBit(std::string date, float nb)
{
	float res;

	res = GetBitValue(date) * nb;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << date << " => " << nb << " = " << res << std::endl;
}

float	BitcoinExchange::GetBitValue(std::string date)
{
	std::map<std::string, float>::const_iterator it;

	it  = _map.find(date);
	if (it != _map.end())
		return (it->second);
	else
	{
		it = _map.lower_bound(date);
		return (it->second);
	}
}