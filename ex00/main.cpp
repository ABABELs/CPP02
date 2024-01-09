/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babels <babels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:19:00 by babels            #+#    #+#             */
/*   Updated: 2024/01/09 12:34:57 by babels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.Class.hpp"

int main(void)
{
    Fixed a;
	std::cout << a.getRawBits() << std::endl;
	a.setRawBits(3);
	std::cout << a.getRawBits() << std::endl;
	Fixed b(a);
	std::cout << b.getRawBits() << std::endl;
	Fixed c;
	c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return (0);
}