/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:54:07 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/31 14:38:50 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	Fixed c(1.2f);
	std::cout << "c => " << c << std::endl;
	std::cout << "(c > a) => " << (c > a) << std::endl;
	std::cout << "(c >= a) => " << (c >= a) << std::endl;
	std::cout << "(c < a) => " << (c < a) << std::endl;
	std::cout << "(c <= a) => " << (c <= a) << std::endl;
	std::cout << "(c == a) => " << (c == a) << std::endl;
	std::cout << "(c != a) => " << (c != a) << std::endl;
	std::cout << "(c + a) => " << (c + a) << std::endl;
	std::cout << "(c + a).getRawBits() => " << (c + a).getRawBits() << std::endl;
	std::cout << "(c - a) => " << (c - a) << std::endl;
	std::cout << "(c - a).getRawBits() => " << (c - a).getRawBits() << std::endl;
	std::cout << "(c * a) => " << (c * a) << std::endl;
	std::cout << "(c * a).getRawBits() => " << (c * a).getRawBits() << std::endl;
	std::cout << "(c / a) => " << (c / a) << std::endl;
	std::cout << "(c / a).getRawBits() => " << (c / a).getRawBits() << std::endl;
	std::cout << "c-- => " << c-- << std::endl;
	std::cout << "c => " << c << std::endl;
	std::cout << "--c => " << --c << std::endl;
	std::cout << "c => " << c << std::endl;
	std::cout << "Fixed::min(c,a) => " << Fixed::min(c, a) << std::endl;

	return 0;
}
