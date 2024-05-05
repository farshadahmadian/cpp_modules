/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:50:15 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/08 12:18:26 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>
#include <cmath>

#define MAX_CAPACITY 1000000
#define RANDOM_NUMBER_RANGE 20

class Span
{
	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &rhs);
		~Span(void);

		unsigned int size(void) const;
		std::list<int> const &getList(void) const;
		void print(void) const;
		void fillList(unsigned int range);
		void checkRange(unsigned int index) const;
		void addNumber(int toBeAdded);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);

	private:
		unsigned int _n;
		std::list<int> _list;
		std::list<int>::iterator _iterator;
		class RangeException;

		std::list<int>::iterator &moveIterator(unsigned int range);
		static void printCurrentValue(int currentValue);
};

class Span::RangeException : public std::exception
{
	public:
		RangeException(void);
		RangeException(int range);
		char const *what() const throw();

	private:
		unsigned short int _range;
};

typedef enum e_exception
{
	NEGATIVE_RANGE = 1,
	OUT_OF_RANGE,
} t_exception;

#endif
