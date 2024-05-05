/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:51:01 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/08 12:16:16 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename F>
void printCurrentValue(F currentValue)
{
	std::cout << currentValue << std::endl;
}

template <typename T, typename F>
void print(T container)
{
	std::for_each(container.begin(), container.end(), printCurrentValue<F>);
}

std::vector<unsigned int> getSpans(std::list<int> list)
{
	std::vector<unsigned int> vector;

	std::list<int>::iterator iterator;
	std::list<int>::iterator iteratorEnd = --list.end();

	for (iterator = list.begin(); iterator != iteratorEnd; iterator++)
	{
		unsigned int span = abs(*iterator - *(++iterator));
		vector.push_back(span);
		iterator--;
	}
	return vector;
}

Span::RangeException::RangeException(void) : std::exception()
{
	return;
}
Span::RangeException::RangeException(int range) : std::exception(), _range(range)
{
	return;
}

char const *Span::RangeException::what() const throw()
{
	if (this->_range == NEGATIVE_RANGE)
		return "Negative Range Exception!\n";
	else if (this->_range == OUT_OF_RANGE)
		return "Out of Range Exception!\n";
	else
		return "Range Exception!\n";
}

Span::Span(void) : _n(0), _list(std::list<int>(0)), _iterator(_list.begin())
{
	return;
}

Span::Span(unsigned int n) : _n(n), _list(0), _iterator(_list.begin())
{
	if (static_cast<int>(n) < 0)
		throw Span::RangeException(NEGATIVE_RANGE);
	else if (n > MAX_CAPACITY)
		throw Span::RangeException(OUT_OF_RANGE);
	this->_list = std::list<int>(n);
	_iterator = this->_list.begin();
	return;
}

Span::Span(Span const &other)
{
	*this = other;
	return;
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_n = rhs._n;
		this->_list = rhs._list;
		this->_iterator = this->_list.begin();
		std::list<int>::const_iterator iteratorCurrentPosition;
		iteratorCurrentPosition = rhs._iterator;
		int movement = std::distance(rhs._list.begin(), iteratorCurrentPosition);
		this->moveIterator(movement);
	}
	return *this;
}

Span::~Span(void)
{
	return;
}

void Span::checkRange(unsigned int const range) const
{
	if (static_cast<int>(range) < 0)
		throw RangeException(NEGATIVE_RANGE);
	else if (range > this->size() || this->_iterator == this->_list.end())
		throw RangeException(OUT_OF_RANGE);
	return;
}

void Span::printCurrentValue(int currentValue)
{
	std::cout << currentValue << std::endl;
	return;
}

void Span::print(void) const
{
	std::for_each(this->_list.begin(), this->_list.end(), Span::printCurrentValue);
	return;
}

std::list<int>::iterator &Span::moveIterator(unsigned int range)
{
	this->checkRange(range);
	for (unsigned int i = 0; i < range; i++)
		this->_iterator++;
	return this->_iterator;
}

int insertCurrentValue(void)
{
	int randomNumber = rand() % RANDOM_NUMBER_RANGE + 1;
	bool isPositive = rand() % 2 == 0 ? false : true;
	if (isPositive)
		return randomNumber;
	else
		return -randomNumber;
}

void Span::fillList(unsigned int range)
{
	this->checkRange(range);
	srand(time(NULL));
	std::generate(this->_list.begin(), moveIterator(range), insertCurrentValue);
	return;
}

unsigned int Span::size(void) const
{
	return this->_n;
}

std::list<int> const &Span::getList(void) const
{
	return this->_list;
}

void Span::addNumber(int toBeAdded)
{
	if (this->_iterator == this->_list.end())
		throw RangeException(OUT_OF_RANGE);
	*_iterator = toBeAdded;
	this->_iterator++;
	return;
}

bool compare(int a, int b)
{
	return a < b;
}

unsigned int Span::shortestSpan(void)
{
	std::list<int> copy;
	copy = this->_list;

	copy.sort(compare);
	std::cout << "sorted copy:\n";
	::print<std::list<int>, int >(copy);

	std::vector<unsigned int> spans = getSpans(copy);
	std::cout << "spans:\n";
	::print<std::vector<unsigned int>, unsigned int >(spans);
	unsigned int minSpan = *std::min_element(spans.begin(), spans.end(), compare);
	std::cout << "minSpan = " << minSpan << std::endl;
	return minSpan;
}

unsigned int Span::longestSpan(void)
{
	typedef std::list<int>::iterator iterator;
	iterator min = std::min_element(this->_list.begin(), this->_list.end(), compare);
	int max = *std::max_element(this->_list.begin(), this->_list.end());
	unsigned int maxSpan = max - *min;
	std::cout << "maxSpan = " << max << " - (" << *min << ") = " << maxSpan << std::endl;

	return	maxSpan;
}
