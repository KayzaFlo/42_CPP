/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:46:19 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/27 16:11:47 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP_
# define SPAN_HPP_
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
# include <vector>
# include <algorithm>
using std::exception;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

class Span
{
private:
	size_t				_maxSize;
	std::vector<int>	_vec;

public:
	Span( void );
	Span( size_t n );
	Span( Span const & src );
	~Span( void );

	Span &	operator=( Span const & rhs );

	void	addNumber( int n );
	size_t	shortestSpan( void ) const;
	size_t	longestSpan( void ) const;

};

#endif // SPAN_HPP_
