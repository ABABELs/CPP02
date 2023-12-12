/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.Class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babels <babels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:36:32 by babels            #+#    #+#             */
/*   Updated: 2023/12/11 15:45:59 by babels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed
{
    public:
        Fixed(void);
        Fixed(Fixed const &src);
        ~Fixed(void);

        Fixed &operator=(Fixed const &rhs);

        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int _rawBits;
        static const int _fractionalBits;
};
#endif