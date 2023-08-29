/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:19:59 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/05 14:51:55 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iomanip>

Phonebook::Phonebook() {
	_start = 0;
	_count = 0;
}

Phonebook::~Phonebook() {}

void	Phonebook::add()
{
	_contacts[(_count + _start) % 8].set_datas();
	if (_count < 8)
		_count++;
	else
		_start = (_start + 1) % 8;
}

void	Phonebook::search(void)
{
	std::string	input;

	for (int i = 0; i < _count; i++)
		_contacts[(i + _start) % 8].display_short(i);
	if (_count) {
		do {
			std::cout << "Show more: ";
			std::cin >> input;
			if (!std::isdigit(input[0]))
			{
				std::cout << "Wrong arg" << std::endl;
				return;
			}
		} while (std::stoi(input) > _count);
		std::cout << (std::stoi(input) + _start) % 8 << std::endl;
		_contacts[(std::stoi(input) + _start) % 8].display_full();
	}
}
