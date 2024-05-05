/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:37:50 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/08 11:58:42 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>
#include "easyfind.hpp"
#include "easyfind.tpp"

int fillContainer(void)
{
	return (rand() % 10 + 1);
}

void print(int currentValue)
{
	std::cout << currentValue << std::endl;
}

template <typename T>
void test(void)
{
	T container(10);
	srand(time(NULL));
	std::generate(container.begin(), container.end(), fillContainer);
	std::for_each(container.begin(), container.end(), print);

	std::cout << "-----------------------" << std::endl;
	int toFind = 2;
	try
	{
		size_t index = easyfind(container, toFind);
		std::cout << "The first " << toFind << " is at index " << index << std::endl;
	}
	catch(std::exception &exception)
	{
		std::cerr << "Didn't find any " << toFind << "! " << exception.what() << std::endl;
	}
}

int main(void)
{
	test<std::vector<int> >();
	test<std::list<int> >();
	return 0;
}