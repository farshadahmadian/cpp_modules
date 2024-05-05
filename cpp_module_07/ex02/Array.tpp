/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:33:05 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/03 18:15:05 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>
# include <stdexcept>
# include <cstring>

template <typename T>
Array<T>::Array(void) : _firstIndex(NULL), _n(0)
{
	return;
}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n)
{
	this->_firstIndex = new T[n];
	memset(this->_firstIndex, 0, sizeof(T) * n);
	return;
}

template <typename T>
Array<T>::Array(Array<T> const &other) : _firstIndex(NULL), _n(other._n) 
{
	*this = other;
	return;
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] this->_firstIndex;
}

template <typename T>
void Array<T>::copyElements(Array<T> const &rhs)
{
	for (unsigned int i = 0; i < this->_n; i++)
		this->_firstIndex[i] = rhs._firstIndex[i];
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	if (this == &rhs)
		return *this;
	if (this->_firstIndex)
		delete [] this->_firstIndex;
	this->_n = rhs._n;
	this->_firstIndex = new T[this->_n];
	copyElements(rhs);
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= this->_n || static_cast<int>(i) < 0)
		throw std::exception();
	return this->_firstIndex[i];
}

template <typename T>
T const &Array<T>::operator[](unsigned int i) const
{
	if (i >= this->_n || static_cast<int>(i) < 0)
		throw std::exception();
	return this->_firstIndex[i];
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return this->_n;
}

template <typename T>
T const *Array<T>::getFirstIndexAddress(void) const
{
	return this->_firstIndex;
}

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> const &array)
{
	o << "Size: " << array.size() << std::endl;
	o << "First index Address: " << array.getFirstIndexAddress() << std::endl;
	for (unsigned int i = 0; i < array.size(); i++)
		o << "Value at index " << i << ": " << (const_cast<Array<T> &>(array))[i] << std::endl;

	return o;
}

#endif
