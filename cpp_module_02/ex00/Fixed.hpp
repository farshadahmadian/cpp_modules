/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:54:01 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/27 16:21:36 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
private:
	int _fixedPointValue;
	static int const _fractionBitsNum;

public:
	Fixed(void);
	Fixed(Fixed const &fixed);
	Fixed &operator=(Fixed const &fixed);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};
