/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack2.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:07:20 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/08 11:08:09 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_TPP
# define MUTANT_STACK_TPP


template <typename T, typename Container >
MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>()
{
	return;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const &other) : std::stack<T>(other)
{
	*this = other;
}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(MutantStack<T, Container> const &rhs)
{
	if (this != &rhs)
	{
		this->c = rhs.c;
	}
	return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void)
{
	return;
}

template <typename T, typename Container>
void MutantStack<T, Container>::identify(void)
{
	this->push(1);
	this->push(11);
	std::cout << "front = " << this->c.front() << std::endl;
	std::cout << "end = " << this->c.back() << std::endl;
	std::cout << "underlying container data type: " << typeid(this->c).name() << std::endl;
}

template <typename T, typename Container>
void MutantStack<T, Container>::useUnderlyingContainerIterator(void)
{
	typename Container::iterator iterator;
	iterator = this->c.begin();
	std::cout << "underlying container's iterator data type: " << typeid(iterator).name() << std::endl;


	return;
}

template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::begin(void)
{
	return this->c.Container::begin();
}

template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::end(void)
{
	return this->c.Container::end();
}

#endif
