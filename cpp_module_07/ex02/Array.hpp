/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:48:09 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/03 18:13:30 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{

public:
	Array<T>(void);
	Array<T>(unsigned int n);
	Array<T>(Array<T> const &other);
	~Array<T>(void);
	Array<T> &operator=(Array<T> const &rhs);
	T &operator[](unsigned int i);
	T const &operator[](unsigned int i) const;
	unsigned int size(void) const;
	T const *getFirstIndexAddress(void) const;

private:
	T *_firstIndex;
	unsigned int _n;
	void copyElements(Array<T> const &rhs);
};

#endif

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> const &array);
