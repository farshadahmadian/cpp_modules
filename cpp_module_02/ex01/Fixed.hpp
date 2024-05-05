/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:40:26 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/22 15:35:58 by fahmadia         ###   ########.fr       */
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
	Fixed(int const originalValue);
	Fixed(float const originalValue);
	Fixed(Fixed const &fixed);
	Fixed const &operator=(Fixed const &fixed);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &cout, Fixed const &fixed);
