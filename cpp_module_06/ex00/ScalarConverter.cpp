/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:30:14 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/27 08:15:59 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "typedef.hpp"

ScalarConverter::ScalarConverter(void)
{
	return;
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
	return;
}

ScalarConverter::~ScalarConverter(void)
{
	return;

}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}

bool ScalarConverter::convert(std::string input)
{	
	std::string const types[] = {"char", "int", "float", "double", "none"};
	bool(*convertors[])(std::string) = {convertToChar, &convertToInt, convertToFloat, &convertToDouble, doNotConvert};
	size_t size = sizeof(types) / sizeof(std::string);
	std::string const type = findType(input, types);

	for (size_t i = 0; i < size; i++)
	{
		if (types[i] == type)
		{
			bool result = convertors[i](input);
			return result;
		}
	}

	return false;
}
