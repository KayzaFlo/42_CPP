/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:42:16 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/28 12:47:10 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

void	mutantStackTests()
{
	cout << C_YEL << "=> " << "Basics\n" << C_WHT;
	MutantStack<int> mstack;
	mstack.push(8);
	mstack.push(17);
	std::cout << ".top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << ".size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	cout << C_YEL << "=> " << "Iterator\n" << C_WHT;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << "*it: " << *it << std::endl;
		++it;
	}
	cout << C_YEL << "=> " << "Copy Constructor\n" << C_WHT;
	std::stack<int> s(mstack);
	std::cout << ".top: " << s.top() << std::endl;
}

void	listTests()
{
	cout << C_YEL << "=> " << "Basics\n" << C_WHT;
	std::list<int> lst;
	lst.push_back(8);
	lst.push_back(17);
	std::cout << ".back: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << ".size: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);
	cout << C_YEL << "=> " << "Iterator\n" << C_WHT;
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << "*it: " << *it << std::endl;
		++it;
	}
	cout << C_YEL << "=> " << "Copy Constructor\n" << C_WHT;
	std::list<int> s(lst);
	std::cout << ".back: " << s.back() << std::endl;
}

int main()
{
	cout << C_CYA << "----- " << "Tests with List<>" << " ------\n" << C_WHT;
	listTests();
	cout << C_CYA << "----- " << "                 " << " ------\n\n" << C_WHT;

	cout << C_CYA << "----- " << "Tests with Mutant<>" << " ------\n" << C_WHT;
	mutantStackTests();
	cout << C_CYA << "----- " << "                   " << " ------\n\n" << C_WHT;
	
	return 0;
}