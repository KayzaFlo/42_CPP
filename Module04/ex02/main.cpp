/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:12 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 15:31:27 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// AAnimal animal;

	{
		const int		count = 11;
		const AAnimal*	animals[count];

		for (int i = 0; i < count; i++)
		{
			if (i % 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
			animals[i]->makeSound();
		}
		for (int i = 0; i < count; i++)
		{
			delete animals[i];
			cout << endl;
		}
	}

	cout << endl;
	Dog dog1;
	cout << endl;
	cout << "dog1:\n";
	dog1.printIdeas(3);
	Dog dog2;
	cout << endl;
	cout << "dog2:\n";
	dog2.printIdeas(3);
	cout << "Copy dog1 to dog2\n";
	dog2 = dog1;
	cout << "dog1:\n";
	dog1.printIdeas(3);
	cout << "dog2:\n";
	dog2.printIdeas(3);
	cout << endl;

	return 0;
}
