/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.Class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babels <babels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:36:32 by babels            #+#    #+#             */
/*   Updated: 2023/12/12 14:25:59 by babels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed(void);
        Fixed(int const n);
        Fixed(float const n);
        Fixed(Fixed const &src);
        ~Fixed(void);

        float toFloat(void) const;
        int toInt(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static Fixed const &min(Fixed const &a, Fixed const &b);
        static Fixed const &max(Fixed const &a, Fixed const &b);

        Fixed &operator=(Fixed const &rhs);
        Fixed &operator+(Fixed const &rhs);
        Fixed &operator-(Fixed const &rhs);
        Fixed &operator*(Fixed const &rhs);
        Fixed &operator/(Fixed const &rhs);
        Fixed &operator++();
        Fixed &operator++(int);
        Fixed &operator--();
        Fixed &operator--(int);

        bool operator>(Fixed const &rhs);
        bool operator<(Fixed const &rhs);
        bool operator>=(Fixed const &rhs);
        bool operator<=(Fixed const &rhs);
        bool operator==(Fixed const &rhs);
        bool operator!=(Fixed const &rhs);
    private:
        int _rawBits;
        static const int _fractionalBits;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);
#endif