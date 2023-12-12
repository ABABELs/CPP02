/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.Class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babels <babels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:45:16 by babels            #+#    #+#             */
/*   Updated: 2023/12/12 15:01:15 by babels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.Class.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0)
{
}

Fixed::Fixed(int const n) : _rawBits(n << Fixed::_fractionalBits)
{
    this->_rawBits = n << this->_fractionalBits;
}

Fixed::Fixed(float const n)
{
    this->_rawBits = roundf(n * (1 << this->_fractionalBits));
}

Fixed::Fixed(Fixed const &src)
{
    this->_rawBits = src.getRawBits();
}

Fixed::~Fixed(void)
{
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    this->_rawBits = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
    this->_rawBits = raw;
}

float Fixed::toFloat(void) const
{
    return (this->getRawBits() / std::pow(2, Fixed::_fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->getRawBits() >> Fixed::_fractionalBits);
}

// arithmetics operators ->
Fixed &Fixed::operator+(Fixed const &rhs)
{
    this->_rawBits += rhs.getRawBits();
    return (*this);
}

Fixed &Fixed::operator-(Fixed const &rhs)
{
    this->_rawBits -= rhs.getRawBits();
    return (*this);
}

Fixed &Fixed::operator*(Fixed const &rhs)
{
    this->_rawBits = (this->toFloat() * rhs.toFloat()) * pow(2, Fixed::_fractionalBits);
    return (*this);
}

Fixed &Fixed::operator/(Fixed const &rhs)
{
    this->_rawBits = (this->toFloat() * rhs.toFloat()) / pow(2, Fixed::_fractionalBits);
    return (*this);
}

Fixed &Fixed::operator++()
{
    this->_rawBits++;
    return (*this);
}

Fixed &Fixed::operator++(int)
{
    Fixed *tmp = new Fixed(*this);
    this->_rawBits++;
    return (*tmp);
}

Fixed &Fixed::operator--()
{
    this->_rawBits--;
    return (*this);
}

Fixed &Fixed::operator--(int)
{
    Fixed *tmp = new Fixed(*this);
    this->_rawBits--;
    return (*tmp);
}
// <- arithmetics operators


// comparison operators ->
std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
    o << rhs.toFloat();
    return (o);
}

bool Fixed::operator>(Fixed const &rhs)
{
    return (this->_rawBits > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const &rhs)
{
    return (this->_rawBits < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs)
{
    return (this->_rawBits >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs)
{
    return (this->_rawBits <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs)
{
    return (this->_rawBits == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs)
{
    return (this->_rawBits != rhs.getRawBits());
}
// <- comparison operators


// min max functions ->
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a.getRawBits() > b.getRawBits() ? a : b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    return (a.getRawBits() > b.getRawBits() ? a : b);
}
// <- min max functions