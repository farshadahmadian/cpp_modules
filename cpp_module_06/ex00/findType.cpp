/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:46:21 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/27 10:53:50 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.hpp"

bool isOnlyOneSign(std::string input)
{
	size_t signIndex = input.find_first_of("-+");
	{
		if (input.find_last_of("-+") > signIndex || (signIndex != std::string::npos && signIndex != 0))
			return false;
	}
	return true;
}

bool isNotDotLast(std::string input)
{
	size_t dotIndex = input.find('.');
	if (dotIndex == input.length() - 1)
		return false;
	return true;
}

bool isTypeChar(std::string input)
{
	size_t length = input.length();
	char c = input[0];
	if(length == 1 && !isdigit(c))
			return true;
	return false;
}

bool isTypeInt(std::string input)
{
	if (!isOnlyOneSign(input))
		return false;
	size_t length = input.length();
	char c = input[0];
	if(length == 1 && isdigit(c))
		return true;
	else if (input.find_first_not_of("+-0123456789") == std::string::npos)
		return true;
	return false;
}

bool isTypeFloat(std::string input)
{
	if (!isOnlyOneSign(input))
		return false;
	if (input.compare("nanf") == 0 || input == "-inff" || input == "+inff" || input == "inff")
		return true;
	if (input.find_first_not_of("+-0123456789.fF") != std::string::npos)
		return false;
	size_t length = input.length();

	size_t firsDotIndex = input.find('.');
	if ( firsDotIndex == std::string::npos)
		return false;

	size_t lastFIndex = input.find_last_of("fF", length - 1);
	if (lastFIndex == std::string::npos)
		return false;

	if (lastFIndex < firsDotIndex || lastFIndex == firsDotIndex + 1 || lastFIndex != length - 1)
		return false;

	if (input.find_last_of('.') > firsDotIndex)
		return false;
	if (input.find_first_of("fF") < lastFIndex)
		return false;
	return true;
}

bool isTypeDouble(std::string input)
{
	if (!isOnlyOneSign(input))
		return false;
	if (input.compare("nan") == 0 || input == "-inf" || input == "+inf" || input == "inf")
		return true;
	if (!isNotDotLast(input))
		return false;
	if (input.find_first_not_of("+-0123456789.") != std::string::npos)
		return false;

	size_t firsDotIndex = input.find('.');
	if ( firsDotIndex == std::string::npos)
		return false;

	if (input.find_last_of('.') > firsDotIndex)
		return false;
	return true;
}

std::string findType(std::string input, std::string const *types)
{
	bool(*typeCheckers[])(std::string) = {isTypeChar, isTypeInt, &isTypeFloat, &isTypeDouble};
	typedef bool(*f)(std::string);

	size_t size = sizeof(typeCheckers) / sizeof(f);

	for (size_t i = 0; i < size; i++)
	{
		if ((typeCheckers[i])(input))
			return types[i];
	}
	return "none";
}
