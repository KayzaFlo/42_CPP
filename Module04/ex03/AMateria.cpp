/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:43:03 by fgeslin           #+#    #+#             */
/*   Updated: 2023/08/01 11:02:28 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("undefined"), _color("") {
	cout << C_GRN << "<AMateria> " << C_WHT;
}

AMateria::AMateria( const string & type ) : _type(type), _color("") {
	cout << C_GRN << "<AMateria(Typed)> " << C_WHT;
}

AMateria::AMateria( const string & type, const string & color ) : _type(type), _color(color) {
	cout << C_GRN << "<AMateria(Typed)> " << C_WHT;
}

AMateria::AMateria( const AMateria &src ) {
	*this = src;
	cout << C_GRN << "<AMateria(Copy)> " << C_WHT;
}

AMateria::~AMateria( void ) {
	cout << C_RED << "~AMateria " << C_WHT;
}

string const &	AMateria::getType( void ) const {
	return _type;
}

string const &	AMateria::getColor( void ) const {
	return _color;
}

AMateria &	AMateria::operator=( AMateria const & rhs ) {
	(void)rhs;
	return *this;
}

void		AMateria::use(ICharacter& target) {
	(void)target;
}
