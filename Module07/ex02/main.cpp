/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:05:28 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/28 14:47:25 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	cout << C_CYA << "-- create null Array --\n" << C_WHT;
	Array<int> zero;

	cout << C_CYA << "-- create random Array = numbers[750] --\n" << C_WHT;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	
	// numbers[42] = 42;
	cout << C_CYA << "-- create tmp by copying numbers --\n" << C_WHT;
	Array<int> tmp = numbers;
	{
		Array<int> test(tmp);
	}

	cout << C_CYA << "-- check if tmp == numbers && values unchanged --\n" << C_WHT;
	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i] || tmp[i] != numbers[i])
			return (std::cerr << "\e[31m/!\\didn't save the same value!!/!\\\n\e[0m", 1);
	}
	cout << "Values correct!\n";

	cout << C_CYA << "-- try to read numbers[-2] --\n" << C_WHT;
	try {
		numbers[-2] = 0;
	}
	catch(const std::exception& e) { std::cerr << C_RED << e.what() << '\n' << C_WHT; }
	cout << C_CYA << "-- try to read numbers[750] --\n" << C_WHT;
	try {
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e) { std::cerr << C_RED << e.what() << '\n' << C_WHT; }

	for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = rand();
	delete [] mirror;//
	return 0;
}