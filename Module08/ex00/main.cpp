/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:43:00 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/27 14:44:00 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <array>
#include <vector>
#include <deque>
#include <list>

void	printint(int i) { cout << i << ", "; }

int main()
{
	cout << C_CYA << "----- Testing with \'array\' -----\n" << C_WHT;
	std::array<int, 3> arr = {1, 2, 3};
	easyfind(arr, 2) ? cout << " ==> Not found\n" : cout << " ==> Found\n";
	easyfind(arr, 4) ? cout << " ==> Not found\n" : cout << " ==> Found\n";
	cout << C_CYA << "-----                       -----\n\n" << C_WHT;

	cout << C_CYA << "----- Testing with \'vector\' -----\n" << C_WHT;
	std::vector<int> vec;
	vec.push_back(8);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(9);
	easyfind(vec, 2) ? cout << " ==> Not found\n" : cout << " ==> Found\n";
	easyfind(vec, 4) ? cout << " ==> Not found\n" : cout << " ==> Found\n";
	cout << C_CYA << "-----                        -----\n\n" << C_WHT;

	cout << C_CYA << "----- Testing with \'deque\' -----\n" << C_WHT;
	std::deque<int> deq;
	deq.push_back(7);
	deq.push_back(5);
	deq.push_back(8);
	easyfind(deq, 8) ? cout << " ==> Not found\n" : cout << " ==> Found\n";
	easyfind(deq, 4) ? cout << " ==> Not found\n" : cout << " ==> Found\n";
	cout << C_CYA << "-----                       -----\n\n" << C_WHT;

	cout << C_CYA << "----- Testing with \'list\' -----\n" << C_WHT;
	std::list<int> lst;
	lst.push_back(7);
	lst.push_back(5);
	lst.push_back(16);
	lst.push_back(8);
	easyfind(lst, 8) ? cout << " ==> Not found\n" : cout << " ==> Found\n";
	easyfind(lst, 4) ? cout << " ==> Not found\n" : cout << " ==> Found\n";
	cout << C_CYA << "-----                      -----\n\n" << C_WHT;

	return 0;
}
