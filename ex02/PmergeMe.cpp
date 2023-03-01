#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void	PmergeMe::printVector()
{
	int i = 0;
	for (std::vector<int>::iterator it = vector_.begin(); it < vector_.end(); it++)
	{
		if(++i > 5)
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void	PmergeMe::printList()
{
	int i = 0;
	for (std::list<int>::iterator it = list_.begin(); it != list_.end(); it++)
	{
		if(++i > 5)
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
	if (!str.empty() && str.find_first_not_of("0123456789") != std::string::npos)
		std::cout << "error\n";
}

void	PmergeMe::ft_sort(char **tab)
{
	double Vtime, Ltime;
	int i = 1;
	int nb = 0;

	while (tab[i])
	{
		is_Num(tab[i]);
		std::istringstream(tab[i]) >> nb;
		if (nb < 0)
			std::cout << "error\n";
		vector_.push_back(nb);
		list_.push_back(nb);
		i++;
	}
	std::cout << "Before :";
	printVector();
	Vtime = VSort();
	Ltime = LSort();
	std::cout << "After :";
	printVector();
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Time to process a range of "<< vector_.size() <<  " elements with std::vector : " << Vtime << " ms\n";
	std::cout << "Time to process a range of "<< list_.size() <<  " elements with std::list : " << Ltime << " ms\n";
}

double PmergeMe::VSort() 
{
	std::clock_t start, end;
	double result;

	start = clock();
	int n = vector_.size();
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = 0; j < n - i - 1; j++) 
		{
			if (vector_[j] > vector_[j + 1]) 
			{
				int temp = vector_[j];
				vector_[j] = vector_[j + 1];
				vector_[j + 1] = temp;
			}
		}
	}
	end = clock();
	result = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	return result;
}

double PmergeMe::LSort() 
{
	std::clock_t start, end;
	double result;

	start = clock();
	for (std::list<int>::iterator i = ++list_.begin(); i != list_.end(); ++i)
	{
		int temp = *i;
		std::list<int>::iterator j = i;
		while (j != list_.begin() && *(--j) > temp)
		{
			*(++j) = *j;
			j--;
		}
		*(++j) = temp;
		j--;
	}
	end = clock();
	result = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	return result;
}
