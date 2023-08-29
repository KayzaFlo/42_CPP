/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:16:21 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/25 14:51:11 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x( Fixed() ), _y( Fixed() ) {}
Point::Point( float x, float y ) : _x( Fixed (x) ), _y( Fixed (y) ) {}
Point::Point( Point const & src ) : _x(src.getX()), _y(src.getY()) {}
Point::~Point() {}

Point &		Point::operator=( Point const & rhs ) {
    (void)rhs;
    return ( *this );
}

Fixed const 	Point::getX(void) const { return _x; }
Fixed const 	Point::getY(void) const { return _y; }
