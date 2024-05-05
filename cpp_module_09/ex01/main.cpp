/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:19:13 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/17 09:36:23 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isValidChar(std::string input)
{
	if (input.find_first_not_of("0123456789+-/* \t") != std::string::npos)
		return false;
	return true;
}

size_t findDelimiters(std::string str, std::string delimiters)
{
	size_t index = str.find_first_of(delimiters);
	return index;
}

std::string &trimeLeft(std::string &str)
{
	size_t firstNoneWspChar = str.find_first_not_of(" \t");
	if (firstNoneWspChar != std::string::npos)
	{
		str = str.substr(firstNoneWspChar, std::string::npos);
		return str;
	}
	else
	{
		str = "";
		return str;
	}
}

std::string &trimeRight(std::string &str)
{
	size_t lastNoneWspChar = str.find_last_not_of(" \t");
	if (lastNoneWspChar != std::string::npos)
		str = str.substr(0, lastNoneWspChar + 1);
	return str;
}

std::string &trim(std::string &str)
{
	str = trimeLeft(str);
	str = trimeRight(str);
	return str;
}

bool areAllCharsSplited(std::string input, std::string delimiters)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		size_t firstWsp = input.find_first_of(delimiters);
		if (firstWsp == 1 || firstWsp == 0)
		{
			input.erase(firstWsp, 1);
			input = input.substr(firstWsp, std::string::npos);
			i--;
		}
		else if (firstWsp > 1 && firstWsp != std::string::npos)
			return false;
		else if (firstWsp == std::string::npos && input.length() > 1 )
			return false;
		else if (firstWsp == std::string::npos && input.length() == 1)
			return true;
	}
	return false;
}

std::string &deleteAllWsp(std::string &input)
{
	std::string::iterator iterator;
	std::string::iterator iteratorEnd = input.end();

	for (iterator = input.begin(); iterator != iteratorEnd; iterator++)
	{
		if (*iterator == ' ' || *iterator == '\t')
		{
			size_t currentIndex = std::distance(input.begin(), iterator);
			input.erase(currentIndex, 1);
			iterator--;
		}
	}

	return input;
}

std::string parseInput(std::string input)
{
	trim(input);
	if (!isValidChar(input) || input.empty())
	{
		std::cerr << "Invalid input!\n";
		return "";
	}

	if (!areAllCharsSplited(input, " \t"))
	{
		std::cerr << "Length more than 1\n";
		return "";
	}

	deleteAllWsp(input);
	return input;
}

int main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cerr << "One argument is required!\n";
		return INVALID_ARGUMENTS_NUM;
	}

	std::string input = parseInput(static_cast<std::string>(argv[1]));
	if (input.empty())
		return INVALID_INPUT;

	if (!RPN::calc(input))
		return INVALID_INPUT;

	return 0;
}
