/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:12 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 13:07:37 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	cout << meta->getType() << "\t";
	meta->makeSound();
	cout << dog->getType() << "\t\t";
	dog->makeSound();
	cout << cat->getType() << "\t\t";
	cat->makeSound();
	delete cat;
	delete dog;
	delete meta;

	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wcat = new WrongCat();
	cout << wmeta->getType() << "\t";
	wmeta->makeSound();
	cout << wcat->getType() << "\t";
	wcat->makeSound();
	delete wcat;
	delete wmeta;

	return 0;
}
