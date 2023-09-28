/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:13:25 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/28 14:47:15 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP_
# define ARRAY_HPP_
# pragma once

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_ITA "\e[3m"
# define C_UND "\e[4m"
# define C_RED "\e[31m"
# define C_GRN "\e[32m"
# define C_YEL "\e[33m"
# define C_BLU "\e[34m"
# define C_MAG "\e[35m"
# define C_CYA "\e[36m"
# define C_GRY "\e[90m"

# include <iostream>
# include <iomanip>
# include <cmath>
using std::exception;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

template <class T>
class Array
{
private:
	uint32_t	_size;
	T *			_tab;

public:
	Array<T>( void ): _size(0), _tab(new T()) {
		cout << "+Array(default)\n";
	}

	Array<T>( uint32_t n ): _size(n), _tab(new T[n]()) {
		cout << "+Array(typed)\n";
	}

	Array<T>( Array const & src ) {
		*this = src;
		cout << "+Array(copy)\n";
	}
	~Array<T>( void ) {
		cout << "~Array\n";
		delete [] _tab;
	}

	Array &	operator=( Array const & rhs ) {
		this->_size = rhs._size;
		delete [] _tab;
		_tab = new T[_size]();
		for (size_t i = 0; i < _size; i++) {
			this->_tab[i] = rhs._tab[i];
		}
		return *this;
	}
	T &		operator[]( size_t pos ) {
		if ( pos < 0 || pos >= _size )
			throw std::out_of_range("\e[31mArray: out of range!\e[0m");
		return _tab[pos];	
	}

	size_t	size( void ) const { return _size; }

};

#endif // ARRAY_HPP_
