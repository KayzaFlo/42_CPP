/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:00:25 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/19 15:24:52 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define	K_GRY "\e[30m"
#define	K_RED "\e[31m"
#define	K_GRE "\e[32m"
#define	K_YEL "\e[33m"
#define	K_WHT "\e[37m"

Harl::Harl() {
	_levels_str[0] = "DEBUG";
	_levels_str[1] = "INFO";
	_levels_str[2] = "WARNING";
	_levels_str[3] = "ERROR";
}

Harl::~Harl(){}

void Harl::_debug(void) const {
	std::cout << K_GRY << "[ DEBUG ]" << K_WHT << std::endl;
	std::cout << "⚪️ This is a Debug Message...\n";
}

void Harl::_info(void) const {
	std::cout << K_GRE << "[ INFO ]" << K_WHT << std::endl;
	std::cout << "🟢 I inform you that this happened.\n";
}

void Harl::_warning(void) const {
	std::cout << K_YEL << "[ WARNING ]" << K_WHT << std::endl;
	std::cout << "🟡 Keep a eye on this, it can become a problem!\n";
}

void Harl::_error(void) const {
	std::cout << K_RED << "[ ERROR ]" << K_WHT << std::endl;
	std::cout << "🔴 An error that must be fixed has been found!!!\n";
}

void Harl::complain(std::string level) const {
	int	i = 0;

    while (i < 4 && _levels_str[i].compare(level))
        i++ ;
		
	switch (i)
	{
	case 0:
		this->_debug();
		this->_info();
		this->_warning();
		this->_error();
		break;
	case 1:
		this->_info();
		this->_warning();
		this->_error();
		break;
	case 2:
		this->_warning();
		this->_error();
		break;
	case 3:
		this->_error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
