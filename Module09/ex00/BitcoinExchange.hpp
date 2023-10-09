/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:25:47 by fgeslin           #+#    #+#             */
/*   Updated: 2023/10/09 14:13:54 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP_
# define BITCOINEXCHANGE_HPP_
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
#include <map>
using std::string;
using std::cout;
using std::endl;

class BitcoinExchange
{
public:
	BitcoinExchange( string path );
	~BitcoinExchange();

private:
	BitcoinExchange( void );
	BitcoinExchange( const BitcoinExchange &src );

	BitcoinExchange &	operator=( BitcoinExchange const & rhs );

	void	parseData();
	void	parseInput( string path );
	float	findRate( int date );
	bool 	isDateValid( string date );

	std::map<int, float> _dataMap;
};

#endif // BITCOINEXCHANGE_HPP_
