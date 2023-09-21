/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:31:37 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/21 12:01:22 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

/*** TEST CLASS ***/
class Data {
public:
	Data( string n, int c) : _name(n), _count(c) {}
	string	_name;
	int		_count;
};
std::ostream &operator<<(std::ostream &o, Data const &rhs) {
	o << "Name: " << rhs._name << " | Count: " << rhs._count;
	return o;
}
/*** TEST CLASS ***/

int main()
{
	string	strTab[] = { "FirstString", "Second", "Third", "Fourth", "Fifth" };
	int		intTab[] = { 42, 21, 9, 0, -5, 15489213, 0 };
	double	doubleTab[] = { 5.55, 2.0, 0.0042 };
	Data	dataTab[] = { Data("Jean", 50), Data("Munch", 2), Data("Soph", -42), Data("Erk", 0)};

	iter( strTab, 5, &print );
	iter( intTab, 7, &print );
	iter( intTab, 2, &print );
	iter( doubleTab, 3, &print );
	iter( dataTab, 4, &print );

	return 0;
}
