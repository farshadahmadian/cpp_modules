/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:23:46 by fahmadia          #+#    #+#             */
/*   Updated: 2024/05/05 17:15:37 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"

std::string trim(std::string input, std::string toTrim)
{
	const size_t start = input.find_first_not_of(toTrim);
	if (start != std::string::npos)
	{
		const size_t end = input.find_last_not_of(toTrim);
		const size_t length = end - start + 1;
		input = input.substr(start, length);
	}
	else
	{
		return "";
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == '\t')
			input[i] = ' ';
	}
	
	return input;
}
