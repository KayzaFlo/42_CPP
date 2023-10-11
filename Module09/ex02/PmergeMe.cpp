/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:11:44 by fgeslin           #+#    #+#             */
/*   Updated: 2023/10/11 15:10:56 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#define INSERTION_TRESHOLD 2

PmergeMe::PmergeMe( int ac, const char** av ) {
	bool	hasDup = false;

	for (int i = 1; i < ac; i++)
	{
		int	val = std::stoi(av[i]);
		if (val < 0)
			throw std::logic_error(C_RED "Error: negative value" C_WHT);
		if (!hasDup) {
			for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++) {
				if (*it == val) {
					hasDup = true;
					break;
				}
			}
		}
		_vec.push_back(val);
		_deq.push_back(val);
	}
	if (hasDup)
		std::cerr << C_YEL "Warning: duplicate\n" C_WHT;

	launchSort();
}

PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe( void ) {}
PmergeMe::PmergeMe( const PmergeMe &src ) { (void)src; }

PmergeMe &	PmergeMe::operator=( PmergeMe const & rhs ) { (void)rhs; return *this; }

void	PmergeMe::launchSort( void ) {
	cout << C_CYA "Before:\t" C_GRY;
	for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); it++)
		cout << *it << " ";
	cout << "\n" C_WHT;

	timeval tStart, tEnd;
	
	gettimeofday(&tStart, NULL);
	sortDeque( 0, _deq.size() - 1 );
	gettimeofday(&tEnd, NULL);
	suseconds_t	tDeque = tEnd.tv_usec - tStart.tv_usec;

	gettimeofday(&tStart, NULL);
	sortVector( 0, _vec.size() - 1 );
	gettimeofday(&tEnd, NULL);
	suseconds_t	tVec = tEnd.tv_usec - tStart.tv_usec;

	cout << C_CYA "After:\t" C_GRY;
	for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); it++)
		cout << *it << " ";
	cout << "\n" C_WHT;

	cout << C_CYA "Time to process a range of " C_YEL << _deq.size() << C_CYA " elements ";
	cout << "with std::deque :\t" C_YEL << std::setprecision(6) << tDeque << C_CYA " µs\n" C_WHT;
	cout << C_CYA "Time to process a range of " C_YEL << _deq.size() << C_CYA " elements ";
	cout << "with std::vector :\t" C_YEL << std::setprecision(6) << tVec << C_CYA " µs\n" C_WHT;

	int	tmp = 0;
	for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); it++) {
		if (*it < tmp)
			throw std::logic_error(C_RED "Error: not sorted\n" C_WHT);
		tmp = *it;
	}
	tmp = 0;
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++) {
		if (*it < tmp)
			throw std::logic_error(C_RED "Error: not sorted\n" C_WHT);
		tmp = *it;
	}
	cout << C_GRN "Sorted!\n" C_WHT;
}

/* ******************************** */
/*			List Sort				*/
/* ******************************** */

void	PmergeMe::insertionDeque( int begin, int end ) {
	for (int i = begin; i < end; i++) {
        int tempVal = _deq[i + 1];
        int j = i + 1;
        while (j > begin && _deq[j - 1] > tempVal) {
            _deq[j] = _deq[j - 1];
            j--;
        }
        _deq[j] = tempVal;
    }
}

void	PmergeMe::mergeDeque( int begin, int mid, int end ) {
	std::deque<int> tmp;

	int leftIdx = begin;
	int rightIdx = mid + 1;
	
	while (leftIdx <= mid || rightIdx <= end) {
		if (rightIdx > end) {
			tmp.push_back(_deq[leftIdx]);
			leftIdx++;
		}
		else if (leftIdx > mid) {
			tmp.push_back(_deq[rightIdx]);
			rightIdx++;
		}
		else if(_deq[leftIdx] <= _deq[rightIdx]) {
			tmp.push_back(_deq[leftIdx]);
			leftIdx++;
		}
		else {
			tmp.push_back(_deq[rightIdx]);
			rightIdx++;
		}
	}
	
	for (int i = begin; i <= end; i++) {
		_deq[i] = tmp[i - begin];
	}
}

void	PmergeMe::sortDeque( int begin, int end ) {
	if (end - begin > INSERTION_TRESHOLD) {
		int	mid = (begin + end) / 2;
		sortDeque( begin, mid );
		sortDeque( mid + 1, end );
		mergeDeque( begin, mid, end );
	}
	else
		insertionDeque( begin, end );
}

/* ******************************** */
/*			Vector Sort				*/
/* ******************************** */

void	PmergeMe::insertionVector( int begin, int end ) {
	for (int i = begin; i < end; i++) {
        int tempVal = _vec[i + 1];
        int j = i + 1;
        while (j > begin && _vec[j - 1] > tempVal) {
            _vec[j] = _vec[j - 1];
            j--;
        }
        _vec[j] = tempVal;
    }
}

void	PmergeMe::mergeVector( int begin, int mid, int end ) {
	std::vector<int> tmp;

	int leftIdx = begin;
	int rightIdx = mid + 1;
	
	while (leftIdx <= mid || rightIdx <= end) {
		if (rightIdx > end) {
			tmp.push_back(_vec[leftIdx]);
			leftIdx++;
		}
		else if (leftIdx > mid) {
			tmp.push_back(_vec[rightIdx]);
			rightIdx++;
		}
		else if(_vec[leftIdx] <= _vec[rightIdx]) {
			tmp.push_back(_vec[leftIdx]);
			leftIdx++;
		}
		else {
			tmp.push_back(_vec[rightIdx]);
			rightIdx++;
		}
	}
	
	for (int i = begin; i <= end; i++) {
		_vec[i] = tmp[i - begin];
	}
}

void	PmergeMe::sortVector( int begin, int end ) {
	if (end - begin > INSERTION_TRESHOLD) {
		int	mid = (begin + end) / 2;
		sortVector( begin, mid );
		sortVector( mid + 1, end );
		mergeVector( begin, mid, end );
	}
	else
		insertionVector( begin, end );
}
