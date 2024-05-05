/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:42:20 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/27 11:10:47 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	std::srand(time(NULL));

	int randomNum = std::rand() % 3;
	Base *base = NULL;

	switch(randomNum)
	{
		case 0:
			base = new A();
			std::cout << "A instance is created" << std::endl;
			break;
		case 1:
			base = new B();
			std::cout << "B instance is created" << std::endl;
			break;;
		default:
			base = new C();
			std::cout << "C instance is created" << std::endl;
			break;
	}
	return base;
}

void identify(Base &p)
{
	try
	{
		A &aRef = dynamic_cast<A &>(p);
		(void)aRef;
		std::cout << "The actual type of p is A" << std::endl;
		return;
	}
	catch(std::exception &castException)
	{
		std::cerr << "p is not a reference to A: " << castException.what() << std::endl;
	}

	try
	{
		B &bRef = dynamic_cast<B &>(p);
		(void)bRef;
		std::cout << "The actual type of p is B" << std::endl;
		return;
	}
	catch(std::exception &castException)
	{
		std::cerr << "p is not a reference to B: " << castException.what() << std::endl;
	}

	try
	{
		C &cRef = dynamic_cast<C &>(p);
		(void)cRef;
		std::cout << "The actual type of p is C" << std::endl;
	}
	catch(std::exception &castException)
	{
		std::cerr << "p is not a reference to C: " << castException.what() << std::endl;
	}
	return;
}

void identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	if (a)
	{
		std::cout << "The actual type of *p is A" << std::endl;
		return;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "The actual type of *p is B" << std::endl;
		return;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "The actual type of *p is C" << std::endl;
		return;
	}
}

int main(void)
{
	Base *p = generate();
	identify(p);

	Base &ref = *p;
	identify(ref);
	delete p;
	return 0;
}
