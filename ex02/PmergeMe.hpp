#ifndef PMERGEME_H
# define PMERGEME_H

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

class PmergeMe
{
private:
	std::vector<int> vector_;
	std::deque<int>	deque_;

public:
	PmergeMe();
	PmergeMe(const PmergeMe & origin);
	PmergeMe & operator=(const PmergeMe & origin);
	~PmergeMe();

	void	ft_sort(char **tab);
	void	printVector();
	void	printDeque();

	template< typename T >
	void	merge_sort(T & lst, int beg, int end) {
		int mid;
		if (beg<end)  
		{
			mid = (beg+end)/2;  
			merge_sort(lst, beg, mid);  
			merge_sort(lst, mid+1, end);  
			merge(lst, beg, mid, end);  
		}
	}

	template< typename T >
	void	merge(T & lst, int left, int mid, int right)  {  
		std::vector<int> temp(right - left + 1);
		int i = left, j = mid+1, k = 0;
		while (i <= mid && j <= right) {
			if (lst[i] <= lst[j]) {
				temp[k++] = lst[i++];
			} else {
				temp[k++] = lst[j++];
			}
		}
		while (i <= mid) {
			temp[k++] = lst[i++];
		}
		while (j <= right) {
			temp[k++] = lst[j++];
		}

		for (int p = 0; p < k; p++) {
			lst[left+p] = temp[p];
		}
	}
};

#endif
