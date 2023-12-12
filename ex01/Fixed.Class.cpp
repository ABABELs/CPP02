/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.Class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babels <babels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:45:16 by babels            #+#    #+#             */
/*   Updated: 2023/12/12 13:32:34 by babels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.Class.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) : _rawBits(n << Fixed::_fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = n << this->_fractionalBits;
}

Fixed::Fixed(float const n)
{
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(n * (1 << this->_fractionalBits));
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_rawBits = src.getRawBits();
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Assignation operator called" << std::endl;
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

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
    o << rhs.toFloat();
    return (o);
}