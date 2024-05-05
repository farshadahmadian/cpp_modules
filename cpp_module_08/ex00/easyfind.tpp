/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:34:08 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/08 12:09:46 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_TPP
# define EASY_FIND_TPP

#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
size_t easyfind(T container, int toFind)
{
	typename T::iterator iterator;

	iterator = std::find(container.begin(), container.end(), toFind);
	if (iterator != container.end())
	{
		std::cout << toFind << " is found!\n";
		return std::distance(container.begin(), iterator);
	}
	throw std::exception();
}

#endif
