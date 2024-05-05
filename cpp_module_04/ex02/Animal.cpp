/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:32:16 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/29 17:48:56 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal(void) : type("Default Type")
{
	std::cout << "Animal class: Default constructor is called." << std::endl;
	return;
}

AAnimal::AAnimal(AAnimal const &animal)
{
	std::cout << "Animal class: Copy constructor is called." << std::endl;
	*this = animal;
	return;
}

AAnimal &AAnimal::operator=(AAnimal const &animal)
{
	if (this != &animal)
		this->type = animal.type;
	return *this;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal class: destructor is called." << std::endl;
}

std::string AAnimal::getType(void) const
{
	return this->type;
}
