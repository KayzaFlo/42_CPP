/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:46:13 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/27 16:37:24 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

string	printArray(int *a, size_t size) {
	string	s;

	s = "{ ";
	for (size_t i = 0; i < size; i++) {
		s += std::to_string(a[i]) + ", ";
	}
	s += "\b\b }";
	return s;
}

int main() {
	std::srand( time ( NULL ) );
	
	// SPAN TOO SMALL
	{
		int		dummy[] = { 1 };
		size_t	size = sizeof(dummy) / sizeof(int);
		cout << C_CYA << "----- " << std::left << std::setw(28) << printArray(dummy, size) << " in Span(8) -----\n" << C_WHT;
		try {
			Span sp = Span(8);
			for (size_t i = 0; i < size; i++) {
				sp.addNumber(dummy[i]);
			}
			int	shortest = sp.shortestSpan();
			std::cout << C_GRN << " ==> " << shortest << C_WHT << std::endl;
			int	longest = sp.longestSpan();
			std::cout << C_GRN << " ==> " << longest << C_WHT << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		cout << C_CYA << "----- " << std::setw(24) << " " << " -----\n\n" << C_WHT;
	}

	// OUT OF RANGE
	{
		int dummy[] = { 6, 3, 9, 11 };
		size_t	size = sizeof(dummy) / sizeof(int);
		cout << C_CYA << "----- " << std::left << std::setw(28) << printArray(dummy, size) << " in Span(3) -----\n" << C_WHT;
		try {
			Span sp = Span(3);
			for (size_t i = 0; i < sizeof(dummy)/sizeof(int); i++) {
				sp.addNumber(dummy[i]);
			}
			int	shortest = sp.shortestSpan();
			std::cout << C_GRN << " ==> " << shortest << C_WHT << std::endl;
			int	longest = sp.longestSpan();
			std::cout << C_GRN << " ==> " << longest << C_WHT << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		cout << C_CYA << "----- " << std::setw(24) << " " << " -----\n\n" << C_WHT;
	}

	{
		int dummy[] = { 6, 3, 9, 11 };
		size_t	size = sizeof(dummy) / sizeof(int);
		cout << C_CYA << "----- " << std::left << std::setw(28) << printArray(dummy, size) << " -----\n" << C_WHT;
		try {
			Span sp = Span(3);
			for (size_t i = 0; i < sizeof(dummy)/sizeof(int); i++) {
				sp.addNumber(dummy[i]);
			}
			int	shortest = sp.shortestSpan();
			std::cout << C_GRN << " ==> " << shortest << C_WHT << std::endl;
			int	longest = sp.longestSpan();
			std::cout << C_GRN << " ==> " << longest << C_WHT << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		cout << C_CYA << "----- " << std::setw(24) << " " << " -----\n\n" << C_WHT;
	}

	{
		cout << C_CYA << "----- " << std::left << std::setw(28) << "random 10,000 in Span(5) -----\n" << C_WHT;
		try {
			std::vector<int>    range( 10000 );
			std::generate( range.begin(), range.end(), rand );
			Span sp = Span( 5 );
			sp.addNumber(range.begin(), range.end());
			int	shortest = sp.shortestSpan();
			std::cout << C_GRN << " ==> " << shortest << C_WHT << std::endl;
			int	longest = sp.longestSpan();
			std::cout << C_GRN << " ==> " << longest << C_WHT << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		cout << C_CYA << "----- " << std::setw(24) << " " << " -----\n\n" << C_WHT;
	}

	{
		cout << C_CYA << "----- " << std::left << std::setw(26) << "random 10,000 -----\n" << C_WHT;
		try {
			std::vector<int>    range( 10000 );
			std::generate( range.begin(), range.end(), rand );
			Span sp = Span( range.size() );
			sp.addNumber(range.begin(), range.end());
			int	shortest = sp.shortestSpan();
			std::cout << C_GRN << " ==> " << shortest << C_WHT << std::endl;
			int	longest = sp.longestSpan();
			std::cout << C_GRN << " ==> " << longest << C_WHT << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		cout << C_CYA << "----- " << std::setw(24) << " " << " -----\n\n" << C_WHT;
	}

	{
		cout << C_CYA << "----- " << std::left << std::setw(26) << "random 999,999 -----\n" << C_WHT;
		try {
			std::vector<int>    range( 999999 );
			std::generate( range.begin(), range.end(), rand );
			Span sp = Span( range.size() );
			sp.addNumber(range.begin(), range.end());
			int	shortest = sp.shortestSpan();
			std::cout << C_GRN << " ==> " << shortest << C_WHT << std::endl;
			int	longest = sp.longestSpan();
			std::cout << C_GRN << " ==> " << longest << C_WHT << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		cout << C_CYA << "----- " << std::setw(24) << " " << " -----\n\n" << C_WHT;
	}
}