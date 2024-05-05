/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:32:16 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/29 17:04:20 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Default Type")
{
	std::cout << "Animal class: Default constructor is called." << std::endl;
	return;
}

Animal::Animal(Animal const &animal)
{
	std::cout << "Animal class: Copy constructor is called." << std::endl;
	*this = animal;
	return;
}

Animal &Animal::operator=(Animal const &animal)
{
	if (this != &animal)
		this->type = animal.type;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal class: destructor is called." << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << this->type << ": General animal sound ..." << std::endl;
}

std::string Animal::getType(void) const
{
	return this->type;
}
