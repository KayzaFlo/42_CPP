/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:11:42 by fgeslin           #+#    #+#             */
/*   Updated: 2023/10/11 14:49:28 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP_
# define PMERGEME_HPP_
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
#include <fstream>
#include <sstream>
#include <deque>
#include <vector>
#include <sys/time.h>
#include <stdio.h>
#include <time.h>
using std::string;
using std::cout;
using std::endl;

class PmergeMe
{
public:
	PmergeMe( int, const char** );
	~PmergeMe();

private:
	PmergeMe( void );
	PmergeMe( const PmergeMe &src );

	PmergeMe &	operator=( PmergeMe const & rhs );
	
	void	launchSort( void );

	void	sortDeque( int, int );
	void	insertionDeque( int, int );
	void	mergeDeque( int, int, int );
	
	void	sortVector( int, int );
	void	insertionVector( int, int );
	void	mergeVector( int, int, int );

	std::vector<int>	_vec;
	std::deque<int>		_deq;
};

#endif // PMERGEME_HPP_