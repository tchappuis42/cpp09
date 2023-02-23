#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void	PmergeMe::printVector()
{
	for (std::vector<int>::iterator it = vector_.begin(); it < vector_.end(); it++)
			std::cout << " " << *it;
	std::cout << std::endl;
}

void	PmergeMe::printList()
{
	for (std::list<int>::iterator it = list_.begin(); it != list_.end(); it++)
			std::cout << " " << *it;
	std::cout << std::endl;
}

void	PmergeMe::ft_sort(char **tab)
{
	double Vtime, Ltime;
	int i = 1;
	int nb = 0;

	while (tab[i])
	{
		std::istringstream(tab[i]) >> nb;
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
	std::cout << "Time to process a range of "<< vector_.size() <<  " elements with std::vector : " << Vtime << " mS\n";
	std::cout << "Time to process a range of "<< list_.size() <<  " elements with std::list : " << Ltime << " mS\n";
}

double PmergeMe::VSort() 
{
	time_t start, end;
	start = time(NULL);
	int n = vector_.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (vector_[j] > vector_[j + 1]) {
				int temp = vector_[j];
				vector_[j] = vector_[j + 1];
				vector_[j + 1] = temp;
			}
		}
	}
	end = time(NULL);
	return end - start;
}

double PmergeMe::LSort() 
{
	time_t start, end;
	start = time(NULL);
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
	end = time(NULL);
	return end - start;
}
