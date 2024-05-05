/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:06:02 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/07 11:02:02 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <stack>
#include <vector>
#include <iostream>
#include <typeinfo>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack<T, Container>(void);
		MutantStack<T, Container>(MutantStack<T, Container> const &other);
		MutantStack<T, Container> &operator=(MutantStack<T, Container> const &rhs);
		~MutantStack<T, Container>(void);
		void identify(void);
		void useUnderlyingContainerIterator(void);
		typename Container::iterator begin(void); 
		typename Container::iterator end(void);
		typedef typename Container::iterator iterator;
};

#endif
