#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & origin)
{
	*this = origin; 
}

PmergeMe & PmergeMe::operator=(const PmergeMe & origin)
{
	this->vector_ = origin.vector_;
	this->deque_ = origin.deque_;
	return *this;
}

void	PmergeMe::printVector()
{
	int i = 0;
	for (std::vector<int>::iterator it = vector_.begin(); it < vector_.end(); it++)
	{
		if(++i > 8)
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void	PmergeMe::printDeque()
{
	int i = 0;
	for (std::deque<int>::iterator it = deque_.begin(); it != deque_.end(); it++)
	{
		if(++i > 8)
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void	is_Num(char *tab)
{
	std::string str = tab;
	if (str[0] == '-')
		throw "Error: not a positive number.";
	if (str.length() > 10 || (str.length() == 10 && str > "2147483647"))
		throw "Error: too large a number.";
	if (!str.empty() && str.find_first_not_of("0123456789") != std::string::npos)
		throw "Error: not a number.";
}

void	PmergeMe::ft_sort(char **tab)
{
	std::clock_t start, end;
	double Vtime, Dtime;
	int i = 1;
	int nb = 0;

	while (tab[i])
	{
		is_Num(tab[i]);
		std::istringstream(tab[i]) >> nb;
		vector_.push_back(nb);
		deque_.push_back(nb);
		i++;
	}
	std::cout << "Before :";
	printVector();
	start = clock();
	merge_sort(vector_, 0, vector_.size() - 1);
	end = clock();
	Vtime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	start = clock();
	merge_sort(deque_, 0, vector_.size() - 1);
	end = clock();
	Dtime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "After :";
	printVector();
	//printDeque();
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Time to process a range of "<< vector_.size() <<  " elements with std::vector : " << Vtime << " ms\n";
	std::cout << "Time to process a range of "<< deque_.size() <<  " elements with std::list : " << Dtime << " ms\n";
}
