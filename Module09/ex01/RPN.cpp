/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:42:49 by fgeslin           #+#    #+#             */
/*   Updated: 2023/10/09 15:50:38 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( string formula ) {
	try	{
		calculate( formula );
		cout << C_CYA << _calculation_stack.top() << C_WHT "\n";
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
}
RPN::~RPN() {}
RPN::RPN( void ) {}
RPN::RPN( const RPN &src ) { (void)src; }

RPN &	RPN::operator=( RPN const & rhs ) { (void)rhs; return *this; }

void	RPN::calculate( string formula ) {
	std::stringstream ss(formula);
	for ( string elem; std::getline(ss, elem, ' '); ) {
		if (elem.size() != 1)
			throw std::logic_error("\e[31mError\e[0m");
			
		else if (std::isdigit(elem[0]))
			_calculation_stack.push(static_cast<float>(elem[0] - '0'));

		else if (elem[0] == '+' || elem[0] == '-' || elem[0] == '*' || elem[0] == '/') {
			if (_calculation_stack.size() < 2)
				throw std::logic_error("\e[31mError\e[0m");
			float	b = _calculation_stack.top();
			_calculation_stack.pop();
			float	a = _calculation_stack.top();
			_calculation_stack.pop();
			switch (elem[0])
			{
			case '+':
				_calculation_stack.push( a + b );
				break;
			case '-':
				_calculation_stack.push( a - b );
				break;
			case '*':
				_calculation_stack.push( a * b );
				break;
			case '/':
				_calculation_stack.push( a / b );
				break;
			}
		}
		else
			throw std::logic_error("\e[31mError\e[0m");
	}
	if (_calculation_stack.size() > 1)
		throw std::logic_error("\e[31mError\e[0m");
}
