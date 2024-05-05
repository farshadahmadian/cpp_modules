/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:09:23 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/16 21:04:31 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"

bool myAtoi(const std::string str, int &num)
{
	int sign = 1;
	int i = 0;

	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\r' ||
				 str[i] == '\f' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	for (size_t j = i; j < str.size(); j++)
	{
		if (!isdigit(str[j]))
			return false;
	}
	if (str[i] == '\0')
		return false;
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (sign == -1)
		num *= -1;
	return true;
}
