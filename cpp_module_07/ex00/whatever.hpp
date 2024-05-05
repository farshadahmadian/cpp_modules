/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 07:10:21 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/31 20:39:24 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHAT_EVER_HPP
# define WHAT_EVER_HPP

template <typename T>
void swap(T &arg1, T &arg2)
{
	T temp;

	temp = arg2;
	arg2 = arg1;
	arg1 = temp;
	return;
}

template <typename T>
T const &min(T const &arg1, T const &arg2)
{
	return (arg1 < arg2 ? arg1 : arg2);
}

template <typename T>
T const &max(T const &arg1, T const &arg2)
{
	return (arg1 > arg2 ? arg1 : arg2);
}


#endif
