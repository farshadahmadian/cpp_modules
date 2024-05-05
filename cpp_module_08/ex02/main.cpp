/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:05:37 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/08 12:19:09 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"

void createMutantStackWithDefaultUnderlyingContainer()
{
	MutantStack<int> mStack;
	mStack.identify();
	mStack.useUnderlyingContainerIterator();
}

void createMutantStackWithVectortUnderlyingContainer()
{
	MutantStack<int, std::vector<int> > mStack2;
	mStack2.identify();
	mStack2.useUnderlyingContainerIterator();
}

void testIteratorBegin(void)
{
		std::deque<int> deque;
		deque.push_back(1);
		deque.push_back(2);
		std::deque<int>::iterator iterator;
		iterator = deque.begin();
		std::cout << "deque: " << *iterator<< std::endl;

		MutantStack<int> mStack;
		mStack.push(1);
		mStack.push(2);
		mStack.begin();
		MutantStack<int>::iterator it = mStack.begin();
		std::cout << "mStack: " << *it<< std::endl;

		return;
}

void testIteratorEnd(void)
{
	std::deque<int> deque;
	deque.push_front(100);
	deque.push_front(200);
	deque.push_front(300);
	std::deque<int>::iterator iteratorFirst = deque.begin();
	std::deque<int>::iterator iteratorEnd = deque.end();
	std::cout << *iteratorFirst << std::endl;
	std::cout << *iteratorEnd << std::endl;

	MutantStack<int, std::deque<int> > mStack;
	mStack.push(100);
	mStack.push(200);
	mStack.push(300);

	MutantStack<int>::iterator iterator = mStack.end();
	std::cout << *iterator << std::endl;
	return;
}

void  test(void)
{
	MutantStack<int> mStack;

	std::cout << std::boolalpha <<"is mStack empty: " << mStack.empty() << std::endl;
	mStack.push(1);
	mStack.push(2);
	mStack.push(3);
	mStack.push(4);
	mStack.push(5);

	std::cout << "size = " << mStack.size() << std::endl;
	std::cout << "top = " << mStack.top() << std::endl;

	mStack.pop();
	
	std::cout << "size = " << mStack.size() << std::endl;
	std::cout << "top = " << mStack.top() << std::endl;

	MutantStack<int>::iterator iteratorFirst = mStack.begin();
	MutantStack<int>::iterator iteratorEnd = mStack.end();
	for (; iteratorFirst != iteratorEnd; iteratorFirst++)
		std::cout << *iteratorFirst << std::endl;

	std::cout << std::boolalpha << "is mStack empty: " << mStack.empty() << std::endl;

	MutantStack<int> copy(mStack);
	MutantStack<int>::iterator itFirst = copy.begin();
	MutantStack<int>::iterator itEnd = copy.end();
	std::cout << "copy: \n";
	for (; itFirst != itEnd; itFirst++)
		std::cout << *itFirst << std::endl;

	MutantStack<int> assign;
	assign = copy;
	std::cout << "assign: \n";
	MutantStack<int>::iterator First = assign.begin();
	MutantStack<int>::iterator End = assign.end();
	for (; First != End; First++)
		std::cout << *First << std::endl;
}

void test2(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return;
}

int main(void)
{
	// createMutantStackWithDefaultUnderlyingContainer();
	// createMutantStackWithVectortUnderlyingContainer();
	// testIteratorBegin();
	// testIteratorEnd();
	// test();
	test2();
	return 0;
}