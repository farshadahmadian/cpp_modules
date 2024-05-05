/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:41:08 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/29 17:41:27 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void fillCatBrain(std::string *ideas)
{
	int i = 0;
	while (i < 100)
	{
		ideas[i] = "Cat idea";
		i++;
	}
	return;
}

void copyCatBrain(Cat &currentCat ,Cat const &other, int size)
{
	for (int i = 0; i < size; i++)
		currentCat.getBrain()->setIdeas(other.getBrain()->getIdeas(), size);
	return;
}

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	this->brain = new Brain(fillCatBrain);
	std::cout << "Cat class: Default constructor is called." << std::endl;
	return;
}

Cat::Cat(Cat const &cat) : Animal(cat)
{
	this->brain = new Brain(fillCatBrain);
	std::cout << "Cat class: copy constructor is called." << std::endl;
	*this = cat;
	return;
}

Cat &Cat::operator=(Cat const &cat)
{
	if (this != &cat)
	{
		this->Animal::operator=(cat);
		copyCatBrain(*this, cat, 100);
	}
	return *this;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Cat class: destructor is called." << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << this->type << ": Meowwwww ..." << std::endl;
	return;
}

Brain *Cat::getBrain(void) const
{
	return this->brain;
}
