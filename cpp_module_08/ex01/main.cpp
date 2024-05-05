/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:54:41 by fahmadia          #+#    #+#             */
/*   Updated: 2024/05/05 17:53:33 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "Span.hpp"

void testConstIterator(void)
{
	Span s1;
	std::list<int>::const_iterator iterator = s1.getList().begin();
	(void)iterator;

	std::list<int> copy = s1.getList();
	std::list<int>::iterator it = copy.begin();
	*it = 7;
	return;
}

int fillList(void)
{
	int random = rand() % 3;
	return random;
}

void testNegativeRange()
{
	try
	{
		Span s1(-1);
	}
	catch(std::exception &exception)
	{
		std::cerr << exception.what();
	}
	return;
}

void testFillingList1(void)
{
	try
	{
		Span s1(5);
		s1.fillList(9);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return;
}

void testFillingList2(void)
{
	try
	{
		Span s1(5);
		s1.fillList(-1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return;
}

void testFillingList3(void)
{
	try
	{
		Span s1(10);
		s1.fillList(5);
		s1.print();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return;
}

void testAssignmentOperator(void)
{

	try
	{
		Span s1(4);
		s1.fillList(2);
		std::cout << "s1:\n";
		s1.print();

		Span s2;
		s2 = s1;
		std::cout << "s2:\n";
		s2.print();

		s2.fillList(1);
		std::cout << "s1:\n";
		s1.print();
		std::cout << "s2:\n";
		s2.print();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return;
}

void testCopyConstructor(void)
{

	try
	{
		Span s1(4);
		s1.fillList(2);
		std::cout << "s1:\n";
		s1.print();

		Span s2 = s1;
		std::cout << "s2:\n";
		s2.print();

		s1.fillList(1);
		std::cout << "s1:\n";
		s1.print();
		std::cout << "s2:\n";
		s2.print();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return;
}

void testNonexplicitConstructor(void)
{
	try
	{
		Span s1(4);
		s1.fillList(2);
		std::cout << "s1:\n";
		s1.print();

		Span s2 = 5;
		std::cout << "s2:\n";
		s2.print();

		s2.addNumber(15);
		std::cout << "s2:\n";
		s2.print();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return;
}

void testAddNumber(void)
{
	Span s1(5);
	try
	{
		s1.fillList(4);
		s1.print();
		s1.addNumber(-50);
		std::cout << "After adding -50\n";
		s1.print();
		s1.addNumber(51);
		s1.fillList(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return;
}

void testShortestSpan(void)
{
	try
	{
		Span s1(MAX_CAPACITY );
		s1.fillList(MAX_CAPACITY);
		std::cout << "s1:\n";
		s1.shortestSpan();
		s1.longestSpan();
	}
	catch(std::exception& exception)
	{
		std::cerr << exception.what();
	}
	return;
}

void testLongesttSpan(void)
{
	Span s1(6);
	s1.fillList(6);
	std::cout << "s1:\n";
	s1.print();
	s1.longestSpan();
	return;
}

void test(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.shortestSpan();
	sp.longestSpan();
	return;
}

int main(void)
{
	// testConstIterator();
	// testNegativeRange();
	// testFillingList1();
	// testFillingList2();
	// testFillingList3();
	// testAssignmentOperator();
	// testCopyConstructor();
	// testNonexplicitConstructor();
	// testAddNumber();
	// testShortestSpan();
	// testLongesttSpan();
	test();
	return 0;
}
