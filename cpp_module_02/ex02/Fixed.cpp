/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:40:59 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/31 14:37:32 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "cmath"

int const Fixed::_fractionBitsNum = 8;

Fixed::Fixed(void) : _fixedPointValue(0)
{
	return;
}

Fixed::Fixed(int const originalValue) : _fixedPointValue(originalValue << _fractionBitsNum)
{
	return;
}

Fixed::Fixed(float const originalValue) : _fixedPointValue(roundf(originalValue * (1 << _fractionBitsNum)))
{
	return;
}

Fixed::Fixed(Fixed const &fixed)
{
	operator=(fixed);
	return;
}

Fixed &Fixed::operator=(Fixed const &fixed)
{
	if (this != &fixed)
		this->setRawBits(fixed.getRawBits());
	return *this;
}

Fixed::~Fixed(void)
{
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

bool Fixed::operator>(Fixed const &fixed) const
{
	if (this->getRawBits() > fixed.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(Fixed const &fixed) const
{
	if (this->getRawBits() < fixed.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(Fixed const &fixed) const
{
	if (this->getRawBits() >= fixed.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(Fixed const &fixed) const
{
	if (this->getRawBits() <= fixed.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(Fixed const &fixed) const
{
	if (this->getRawBits() == fixed.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(Fixed const &fixed) const
{
	if (this->getRawBits() != fixed.getRawBits())
		return true;
	return false;
}

Fixed Fixed::operator+(Fixed const &fixed) const
{
	float result = this->toFloat() + fixed.toFloat();
	Fixed resultFixed = Fixed(result);
	return resultFixed;
}

Fixed Fixed::operator-(Fixed const &fixed) const
{
	float result = this->toFloat() - fixed.toFloat();
	Fixed resultFixed(result);
	return resultFixed;
}

Fixed Fixed::operator*(Fixed const &fixed) const
{
	Fixed resultFixed(this->toFloat() * fixed.toFloat());
	return resultFixed;
}

Fixed Fixed::operator/(Fixed const &fixed) const
{
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int a)
{
	a = 1;
	Fixed temp(*this);
	this->setRawBits(this->getRawBits() + a);
	return temp;
}

Fixed &Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int a)
{
	a = 1;
	Fixed temp;
	temp = *this;
	this->setRawBits(this->getRawBits() - a);
	return temp;
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return fixed1;
	return fixed2;
}

Fixed const &Fixed::min(Fixed const &fixed1, Fixed const &fixed2)
{
	return fixed1.getRawBits() < fixed2.getRawBits() ? fixed1 : fixed2;
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	return fixed1.getRawBits() > fixed2.getRawBits() ? fixed1 : fixed2;
}

Fixed const &Fixed::max(Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return fixed1;
	return fixed2;
}
