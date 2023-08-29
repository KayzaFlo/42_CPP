/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:19:59 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/19 13:40:18 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iomanip>

Contact::Contact() {}

Contact::~Contact() {}

void	Contact::set_datas() {
	std::cout << "first name: ";
	std::cin >> _first_name;
	std::cout << "last name: ";
	std::cin >> _last_name;
	std::cout << "nickname: ";
	std::cin >> _nickname;
	std::cout << "phone number: ";
	std::cin >> _phone_number;
	std::cout << "darkest secret: ";
	std::cin >> _darkest_secret;
	std::cout << "Saved!" << std::endl;
}

std::string format_cell(std::string str, uint64_t n) {
	if (str.length() > n) 
		str[n - 1] = '.';
	str.resize(n, ' ');
	return (str);
}

void	Contact::display_short(int i) {
	std::cout << std::setw(10) << std::left << std::to_string(i);
	std::cout << "|";
	std::cout << std::setw(10) << std::left << format_cell(_first_name, 10);
	std::cout << "|";
	std::cout << std::setw(10) << std::left << format_cell(_last_name, 10);
	std::cout << "|";
	std::cout << std::setw(10) << std::left << format_cell(_nickname, 10);
	std::cout << std::endl;
}

void	Contact::display_full() {
	std::cout << _first_name << std::endl;
	std::cout << _last_name << std::endl;
	std::cout << _nickname << std::endl;
	std::cout << _phone_number << std::endl;
	std::cout << _darkest_secret << std::endl;
}
