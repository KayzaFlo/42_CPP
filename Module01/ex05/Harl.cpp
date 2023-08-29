/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:00:25 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/19 16:07:37 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	_levels_str[0] = "DEBUG";
	_levels_str[1] = "INFO";
	_levels_str[2] = "WARNING";
	_levels_str[3] = "ERROR";
	
	_levels_fun[0] = &Harl::_debug;
	_levels_fun[1] = &Harl::_info;
	_levels_fun[2] = &Harl::_warning;
	_levels_fun[3] = &Harl::_error;
}

Harl::~Harl(){}

void Harl::_debug(void) const {
	std::cout << "\033[1;30mThis is a Debug Message..." << std::endl;
}

void Harl::_info(void) const {
	std::cout << "\033[0;37mI inform you that this happened." << std::endl;
}

void Harl::_warning(void) const {
	std::cout << "\033[0;33mKeep a eye on this, it can become a problem!" << std::endl;
}

void Harl::_error(void) const {
	std::cout << "\033[0;31mAn error that must be fixed has been found!!!" << std::endl;
}

void Harl::complain(std::string level) const {
	for (size_t i = 0; i < 4; i++) {
		if (level == _levels_str[i]) {
			(this->*_levels_fun[i])();
			return;
		}
	}
	std::cout << "\033[0;37mWrong input!" << std::endl;
}
