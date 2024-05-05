/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:42:17 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/29 17:04:55 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	std::cout << "Dog class: Default constructor is called." << std::endl;
	return;
}

Dog::Dog(Dog const &dog) : Animal(dog)
{
	std::cout << "Dog class: Copy constructor is called." << std::endl;
	return;
}

Dog &Dog::operator=(Dog const &dog)
{
	if (this != &dog)
		this->type = dog.type;
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog class: destructor is called." << std::endl;
	return;
}

void Dog::makeSound(void) const
{
	std::cout << this->type << ": Houf houf ..." << std::endl;
}
