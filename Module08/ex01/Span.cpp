/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:46:15 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/27 16:11:40 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) : _maxSize(0) {}
Span::Span( size_t n ) : _maxSize(n) {}
Span::Span( Span const & src ) { *this = src; }
Span::~Span( void ) {}

Span &	Span::operator=( Span const & rhs ) {
	(void)rhs;
	return *this;
}

void	Span::addNumber( int n ) {
	if (_vec.size() < _maxSize)
		_vec.push_back(n);
	else
		throw std::out_of_range("Span full!");
}

size_t	Span::shortestSpan( void ) const {
	if (_vec.size() < 2)
		throw exception();
		
	std::vector<int> tmp;
	for (size_t i = 0; i < _vec.size(); i++) 
		tmp.push_back(_vec[i]);
	std::sort(tmp.begin(), tmp.end());

	int	shortestGap = tmp[1] - tmp[0];
	int	a = tmp[1], b = tmp[0];
	for (size_t i = 0; i < tmp.size() - 1; i++) {
		if (tmp[i + 1] - tmp[i] < shortestGap) {
			a = tmp[i + 1];
			b = tmp[i];
			shortestGap = tmp[i + 1] - tmp[i];
		}
	}
	cout << "Smallest gap is between \'" << a << "\' and \'" << b << "\'.\n";
	return shortestGap;
}

size_t	Span::longestSpan( void ) const {
	if (_vec.size() < 2)
		throw exception();
		
	int	min = *std::min_element(_vec.begin(), _vec.end());
	int	max = *std::max_element(_vec.begin(), _vec.end());
	cout << "Bigest gap is between \'" << max << "\' and \'" << min << "\'.\n";
	return max - min;
}
