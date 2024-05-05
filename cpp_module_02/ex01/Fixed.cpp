/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:40:23 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/24 08:27:13 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

int const Fixed::_fractionBitsNum = 8;

Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(int const originalValue) : _fixedPointValue(originalValue << _fractionBitsNum)
{
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed(float const originalValue) : _fixedPointValue(roundf(originalValue * (1 << _fractionBitsNum)))
{
	std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(fixed);
	return;
}

Fixed const &Fixed::operator=(Fixed const &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->setRawBits(fixed.getRawBits());
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int Fixed::getRawBits(void) const
{
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
	return;
}

float Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / (1 << _fractionBitsNum));
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> _fractionBitsNum);
}

std::ostream &operator<<(std::ostream &cout, Fixed const &fixed)
{
	cout << fixed.toFloat();
	return cout;
}
