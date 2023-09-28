/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:42:49 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/28 12:47:39 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP_
# define MUTANTSTACK_HPP_
# pragma once

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_ITA "\e[3m"
# define C_UND "\e[4m"
# define C_RED "\e[31m"
# define C_GRN "\e[32m"
# define C_YEL "\e[33m"
# define C_BLU "\e[34m"
# define C_MAG "\e[35m"
# define C_CYA "\e[36m"
# define C_GRY "\e[90m"

# include <iostream>
# include <stack>
using std::string;
using std::cout;
using std::endl;

template< typename T >
class MutantStack : public std::stack<T>
{
public:
	struct iterator {
		iterator(T* ptr) : m_ptr(ptr) {}

		T& operator*() const { return *m_ptr; }
		T* operator->() { return m_ptr; }

		iterator& operator++() { m_ptr++; return *this; }
		iterator& operator--() { m_ptr--; return *this; }
		iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
		iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; }

		bool operator== (const iterator& rhs) { return m_ptr == rhs.m_ptr; };
		bool operator!= (const iterator& rhs) { return m_ptr != rhs.m_ptr; };
		
		private:
			T* m_ptr;
	};
	
	MutantStack( void ) {}
	MutantStack( MutantStack const & src ) { *this = src; }
	~MutantStack( void ) {}
	MutantStack &	operator=( MutantStack const & rhs ) { (void)rhs; return *this; }

	iterator	begin( void ) {
		std::stack<T>	tmp;
		while (this->size() > 1) {
			tmp.push(this->top());
			this->pop();
		}
		iterator	begin(&this->top());
		while (tmp.size() > 0) {
			this->push(tmp.top());
			tmp.pop();
		}
		return begin;
	}
	iterator	end( void ) {
		iterator	end(&this->top());
		end++;
		return end;
	}

};

#endif // MUTANTSTACK_HPP_
