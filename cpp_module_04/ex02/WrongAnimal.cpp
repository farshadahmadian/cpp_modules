/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:28:40 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/26 17:53:58 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Default Wrong Animal")
{
	std::cout << "WrongAnimal class: Default constructor is called." << std::endl;
	return;
}

WrongAnimal::WrongAnimal(std::string const type) : type(type)
{
	std::cout << "WrongAnimal class: Parameterized constructor is called." << std::endl;
	return;
}

WrongAnimal::WrongAnimal(WrongAnimal const &wrongAnimal)
{
	*this = wrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &wrongAnimal)
{
	if (this != & wrongAnimal)
		this->type = wrongAnimal.type;
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal class: destructor is called." << std::endl;
	return;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << this->type << ": General animal sound ..." << std::endl;
	return;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}
