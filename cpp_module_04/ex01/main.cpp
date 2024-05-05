/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:11:20 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/29 18:10:50 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#ifndef N
#define N 2
#endif

int main(void)
{

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;


	Animal *animals[N];
	for (int i = 0; i < N / 2; i++)
	{
		animals[i] = new Dog();
	}

	for (int i = N/2; i < N; i++)
	{
		animals[i] = new Cat();
	}
	
	
	for (int i = 0; i < N; i++)
	{
		animals[i]->makeSound();
		delete animals[i];
	}

	Dog dog1;
	Dog dog2 = dog1;

	dog1.getBrain()->setIdeasDefault( "I need to find food", 1);

	std::cout << "dog1's first idea: " << dog1.getBrain()->getIdeas()[0] << std::endl;
	std::cout << "dog2's first idea: " << dog2.getBrain()->getIdeas()[0] << std::endl;

	Cat cat1 = Cat();
	Cat cat2(cat1);

	cat1.getBrain()->setIdeasDefault("I want to play", 1);

	std::cout << "cat1's first idea: " << cat1.getBrain()->getIdeas()[0] << std::endl;
	std::cout << "cat2's first idea: " << cat2.getBrain()->getIdeas()[0] << std::endl;

	return 0;
}
