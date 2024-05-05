/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:31:58 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/27 20:07:29 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	WrongAnimal *meta2 = new WrongAnimal();
	WrongAnimal *i2 = new WrongCat();

	std::cout << "meta2->getType() = " << meta2->getType() << std::endl;
	std::cout << "i2->getType() = " << i2->getType() << std::endl;

	meta2->makeSound();
	i2->makeSound();

	delete meta2;
	delete i2;
	return 0;
}
