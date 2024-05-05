/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:42:17 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/29 17:48:11 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void fillDogBrain(std::string *ideas)
{
	int i = 0;
	while (i < 100)
	{
		ideas[i] = "dog idea";
		i++;
	}
	return;
}

Dog::Dog(void) : AAnimal()
{
	this->type = "Dog";
	this->brain = new Brain(fillDogBrain);
	std::cout << "Dog class: Default constructor is called." << std::endl;
	return;
}

Dog::Dog(Dog const &dog) : AAnimal(dog)
{
	this->brain = new Brain(fillDogBrain);
	std::cout << "Dog class: copy constructor is called." << std::endl;
	*this = dog;
	return;
}

void copyDogBrain(Dog &currentDog ,Dog const &other)
{
	for (int i = 0; i < 100; i++)
			currentDog.getBrain()->setIdeas(other.getBrain()->getIdeas(), 100);
	return;
}

Dog &Dog::operator=(Dog const &dog)
{
	if (this != &dog)
	{
		this->AAnimal::operator=(dog);
		copyDogBrain(*this, dog);
	}
	return *this;
}

Dog::~Dog(void)
{
	delete this->getBrain();
	std::cout << "Dog class: destructor is called." << std::endl;
	return;
}

void Dog::makeSound(void) const
{
	std::cout << this->type << ": Houf houf ..." << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return this->brain;
}
