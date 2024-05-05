/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:38:15 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/04 14:46:02 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <iomanip>

template <typename T>
void callback(T currentElement)
{
	std::cout <<  currentElement << std::endl;
}

template <typename T>
void iter(T *arr, size_t length, void(*functionPtr)(T))
{
	if (static_cast<int>(length) < 0)
		return;
	for (size_t i = 0; i < length; i++)
		functionPtr(arr[i]);
	return;
}

template <typename T, typename Function>
void iter(T *arr, size_t length, Function f)
{
	if (static_cast<int>(length) < 0)
		return;
	for (size_t i = 0; i < length; i++)
		f(*(arr + i));
	return;
}

#endif
