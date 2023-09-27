/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:05:28 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/27 13:05:28 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	Array<int> zero;
	int* mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	
	Array<int> tmp = numbers;
	{
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i] || tmp[i] != numbers[i])
			return (std::cerr << "didn't save the same value!!\n", 1);
	}

	try {
		numbers[-2] = 0;
	}
	catch(const std::exception& e) { std::cerr << C_RED << e.what() << '\n' << C_WHT; }
	try {
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e) { std::cerr << C_RED << e.what() << '\n' << C_WHT; }

	for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = rand();
	delete [] mirror;//
	return 0;
}