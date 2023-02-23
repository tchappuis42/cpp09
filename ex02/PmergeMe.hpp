#ifndef PMERGEME_H
# define PMERGEME_H

#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <time.h>

class PmergeMe
{
private:
	std::vector<int> vector_;
	std::list<int>	list_;

public:
	PmergeMe();
	~PmergeMe();

	void	ft_sort(char **tab);
	void	printVector();
	void	printList();
	double	VSort();
	double	LSort();
};

#endif
