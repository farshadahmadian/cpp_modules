/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:41:08 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/29 17:04:42 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	std::cout << "Cat class: Default constructor is called." << std::endl;
	return;
}

Cat::Cat(Cat const &cat) : Animal(cat)
{
	std::cout << "Cat class: Copy constructor is called." << std::endl;
	return;
}

Cat &Cat::operator=(Cat const &cat)
{
	if (this != &cat)
		this->type = cat.type;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat class: destructor is called." << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << this->type << ": Meowwwww ..." << std::endl;
	return;
}
