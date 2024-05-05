/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:33:34 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/29 17:11:55 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat class: Default constructor is called." << std::endl;
	return;
}

WrongCat::WrongCat(std::string const type) : WrongAnimal(type)
{
	std::cout << "WrongCat class: Parameterized constructor is called." << std::endl;
	return;
}

WrongCat::WrongCat(WrongCat const &wrongCat) : WrongAnimal(wrongCat)
{
	std::cout << "WrongCat class: Copy constructor is called." << std::endl;
	return;
}

WrongCat &WrongCat::operator=(WrongCat const &wrongCat)
{
	if (this != &wrongCat)
		this->type = wrongCat.type;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat class: destructor is called." << std::endl;
	return;
}

void WrongCat::makeSound(void) const
{
	std::cout << this->type << ": Meowwwww ..." << std::endl;
	return;
}
