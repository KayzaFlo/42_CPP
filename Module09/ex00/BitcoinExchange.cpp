/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:26:07 by fgeslin           #+#    #+#             */
/*   Updated: 2023/10/09 14:27:05 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ) {}

BitcoinExchange::BitcoinExchange( string path ) {
	try
	{
		parseData();
		parseInput( path );
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &src ) { (void)src; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &	BitcoinExchange::operator=( BitcoinExchange const & rhs ) { (void)rhs; return *this; }

void	BitcoinExchange::parseData() {
	string header;
	std::ifstream dataFile("data.csv");
	std::getline(dataFile, header);

	for ( string line; std::getline(dataFile, line); ) {
		line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
		size_t	del = line.find(',');
		if (del == string::npos)
			throw std::logic_error("\e[31mError: Data: bad input.\e[0m");
		string	date = line.substr(0, del);
		if (!isDateValid(date)) {
			dataFile.close();
			throw std::logic_error("\e[31mError: Data: bad time format.\e[0m");
		}

		int	rate = std::stof(line.substr(del + 1));
		int	iDate = std::stoi(line.substr(0, 4) + line.substr(5, 2) + line.substr(8, 2));
		_dataMap.insert(std::make_pair(iDate, rate));
	}
	dataFile.close();
}

void	BitcoinExchange::parseInput( string path ) {
	string	header;
	std::ifstream inputFile(path);
	std::getline(inputFile, header);

	for ( string line; std::getline(inputFile, line); ) {
		try
		{
			line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
			size_t	del = line.find('|');
			if (del == string::npos)
				throw std::logic_error("\e[31mError: bad input => " + line + C_WHT);
			string	date = line.substr(0, 10);
			if (!isDateValid(date))
				throw std::logic_error("\e[31mError: bad time format => " + line + C_WHT);

			float	count = std::stof(line.substr(del + 1));
			if (count < 0)
				throw std::out_of_range("\e[31mError: not a positive number.\e[0m");
			if (count > 1000)
				throw std::out_of_range("\e[31mError: too large number.\e[0m");
				
			int		iDate = std::stoi(line.substr(0, 4) + line.substr(5, 2) + line.substr(8, 2));
			float	price = findRate(iDate) * count;
			cout << date << " => " << count << " = " << price << endl;
		}
		catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	}
	inputFile.close();
}

float	BitcoinExchange::findRate( int date ) {
	
	for (std::map<int, float>::const_iterator it = --_dataMap.end(); it != --_dataMap.begin(); --it) {
		if (it->first <= date)
			return it->second;
	}
	throw std::out_of_range("\e[31mError: date not referenced.\e[0m");
}

bool BitcoinExchange::isDateValid(string date) {
    std::tm timeStruct = { .tm_year = 0, .tm_mon = 0, .tm_mday = 0, .tm_hour = 0, .tm_min = 0, .tm_sec = 0 };
    std::istringstream iss(date);
    iss >> std::get_time(&timeStruct, "%Y-%m-%d");
    return (!iss.fail());
}
