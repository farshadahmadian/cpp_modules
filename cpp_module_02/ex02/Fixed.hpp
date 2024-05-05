/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:40:25 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/27 17:29:59 by fahmadia         ###   ########.fr       */
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
	Fixed &operator=(Fixed const &fixed);
	~Fixed(void);
	bool operator>(Fixed const &fixed) const;
	bool operator<(Fixed const &fixed) const;
	bool operator>=(Fixed const &fixed) const;
	bool operator<=(Fixed const &fixed) const;
	bool operator==(Fixed const &fixed) const;
	bool operator!=(Fixed const &fixed) const;
	Fixed operator+(Fixed const &fixed) const;
	Fixed operator-(Fixed const &fixed) const;
	Fixed operator*(Fixed const &fixed) const;
	Fixed operator/(Fixed const &fixed) const;
	Fixed &operator++(void);
	Fixed operator++(int a);
	Fixed &operator--(void);
	Fixed operator--(int a);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	static Fixed &min(Fixed &fixed1, Fixed &fixed2);
	static Fixed const &min(Fixed const &fixed1, Fixed const &fixed2);
	static Fixed &max(Fixed &fixed1, Fixed &fixed2);
	static Fixed const &max(Fixed const &fixed1, Fixed const &fixed2);
};

std::ostream &operator<<(std::ostream &cout, Fixed const &fixed);
