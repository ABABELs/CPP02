/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babels <babels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:19:00 by babels            #+#    #+#             */
/*   Updated: 2024/01/09 13:09:18 by babels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.Class.hpp"

int main( void )
{
	Fixed		a;
	Fixed		b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const	c( Fixed( 5.05f ) / Fixed( 2 ) );
	Fixed		d;
	
	std::cout << b << " b" << std::endl;
	std::cout << c << " c" << std::endl;
	a = b;
	std::cout << a << " display a" <<std::endl;
	std::cout << ++a << " ++a" << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << " a++" << std::endl;
	std::cout << a << " display a" << std::endl;

	d = c;
	std::cout << d << " display d" <<std::endl;
	std::cout << --d << " --d" << std::endl;
	std::cout << d << std::endl;
	std::cout << d-- << " d--" << std::endl;
	std::cout << d << " display d" << std::endl;
	
	if (a > b)
		std::cout << "a < b" << std::endl;
	if (b <= a)
		std::cout << "a >= b" << std::endl;
	if (a >= b)
		std::cout << "a <= b" << std::endl;
	if (b < a)
		std::cout << "a > b" << std::endl;

	std::cout << Fixed::max(a, d) << " max between " << a << " and " << d << std::endl;
	std::cout << Fixed::max(b, c) << " max between " << b << " and " << c << std::endl;
	std::cout << Fixed::min(a, d) << " min between " << a << " and " << d << std::endl;
	std::cout << Fixed::min(b, c) << " min between " << b << " and " << c << std::endl;
	
	return 0;
}