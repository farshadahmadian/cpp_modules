/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertToTypes.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:12:41 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/27 14:30:33 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.hpp"

void printCahr(int a, char castedToChar)
{
	a < 32 || a > 126 ?
		std::cout << "char: " << "Non displayable" << std::endl
		:
		std::cout << "char: " << "'" << castedToChar << "'" << std::endl;
}

void printInt(long int a, int num)
{
	int maxInt = std::numeric_limits<int>::max();
	int minInt = std::numeric_limits<int>::min();

	if (a > static_cast<long>(maxInt) || a < minInt)
	{
		std::cerr << "int: " << "impossible" << std::endl;
		return;
	}
	std::cout << "int: " << num << std::endl;
}

void printFloat(double a, float number, size_t fractionalDigitsNum)
{
	float floatMax = std::numeric_limits<float>::max();
	float floatMin =  -floatMax;
	if (a > static_cast<double>(floatMax) || a < floatMin)
	{
		std::cout << "float: " << "impossible" << std::endl;
		return;
	}
	std::cout << std::fixed << std::setprecision(fractionalDigitsNum) << "float: " << number << 'f' << std::endl;
}

bool convertToChar(std::string input)
{
	char c = input[0];
	int castedToInt = static_cast<int>(c);
	float castedToFloat = static_cast<float>(castedToInt);
	double castedToDouble = static_cast<double>(castedToFloat);
	std::cout << "char: " << "'" << c << "'" << std::endl;
	std::cout << "int: " << castedToInt << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << castedToFloat << 'f' << std::endl;
	std::cout << "double: " << castedToDouble << std::endl;
	return true;
}

bool convertToInt(std::string input)
{
	std::istringstream stream;
	stream.str(input);
	long a; 
	stream >> a;
	
	int maxInt = std::numeric_limits<int>::max();
	int minInt = std::numeric_limits<int>::min();

	if (a > static_cast<long>(maxInt) || a < minInt)
	{
		std::cerr << "Out of int range!" << std::endl;
		return false;
	}
	int num;
	stream.clear();
	stream.str(input);
	stream >> num;
	char castedToChar = static_cast<char>(num);
	float castedToFloat = static_cast<float>(num);
	double castedToDouble = static_cast<double>(num);
	printCahr(a, castedToChar);
	std::cout << "int: " << num << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << castedToFloat << "f" << std::endl;
	std::cout << "double: " << castedToDouble  << std::endl;
	return true;
}

void handleNanfAndInff(float f, int sign)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	if (sign == NONE)
	{
		std::cout << "float: " << f << 'f' << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
	else if (sign == POSITIVE || sign == NEGATIVE)
	{
		std::cout << "float: " << (sign == POSITIVE ? '+' : '-') << f << 'f' << std::endl;
		std::cout << "double: " << (sign == POSITIVE ? '+' : '-') << static_cast<double>(f) << std::endl;
	}
	return;
}

size_t countFractionalDigits(std::string input)
{
	size_t dotIndex = input.find('.');
	std::string afterDot = input.substr(dotIndex + 1, std::string::npos);
	size_t length = afterDot.length();
	return length;
}

bool isNanf(std::string input)
{
	if (input.compare("nanf") == 0)
	{
		float f = nanf("");
		handleNanfAndInff(f, NONE);
		return true;
	}
	return false;
}

bool isInff(std::string input)
{
	if (input == "-inff" || input == "+inff" || input == "inff")
	{
		float f = std::numeric_limits<float>::infinity();
		int sign;
		if (input[0] == '-')
			sign = NEGATIVE;
		else if (input[0] == '+')
			sign = POSITIVE;
		else
			sign = NONE;
		return(handleNanfAndInff(f, sign), true);
	}
	return false;
}

bool convertToFloat(std::string input)
{
	if (isNanf(input))
		return true;
	if (isInff(input))
		return	true;
	size_t length = input.length();
	float floatMax = std::numeric_limits<float>::max();
	float floatMin = -floatMax;
	std::istringstream stream;
	input.erase(length - 1, 1);
	stream.str(input);
	double d;
	stream >> d;
	if (d > floatMax || d < floatMin)
	{
		std::cerr << "The number is out of the float numbers range!" << std::endl;
		return false;
	}
	float f;
	stream.clear();
	stream.str(input);
	stream >> f;
	size_t FractionalDigitsNum = countFractionalDigits(input);
	int castedToInt = static_cast<int>(f);
	char castedToChar = static_cast<char>(castedToInt);
	double castedToDouble = static_cast<double>(f);
	printCahr(castedToInt, castedToChar);
	printInt(static_cast<long>(f), castedToInt);
	std::cout << std::fixed << std::setprecision(static_cast<int>(FractionalDigitsNum)) << "float: " << f << 'f' << std::endl;
	std::cout << "double: " << castedToDouble << std::endl;
	return true;
}

void handleNanAndInf(double d, int sign)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	if (sign == NONE)
	{
		std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else if (sign == POSITIVE || sign == NEGATIVE)
	{
		std::cout << "float: " << (sign == POSITIVE ? '+' : '-') << static_cast<float>(d) << 'f' << std::endl;
		std::cout << "double: " << (sign == POSITIVE ? '+' : '-') << d << std::endl;
	}
	return;
}

bool isNan(std::string input)
{
	if (input.compare("nan") == 0)
	{
		double d = nan("");
		return (handleNanAndInf(d, NONE), true);
	}
	return false;
}

bool isInf(std::string input)
{
	if (input == "-inf" || input == "+inf" || input == "inf")
	{
		int sign;
		if (input[0] == '-')
			sign = NEGATIVE;
		else if (input[0] == '+')
			sign = POSITIVE;
		else
			sign = NONE;
		double d = std::numeric_limits<double>::infinity();
		handleNanAndInf(d, sign);
		return true;
	}
	return false;
}

bool convertToDouble(std::string input)
{
	if (isNan(input))
		return true;
	if (isInf(input))
		return true;
	double doubleMax = std::numeric_limits<double>::max();
	double doubleMin =  -doubleMax;
	std::istringstream stream(input);
	long double d;
	stream >> d;
	if (d > static_cast<long double>(doubleMax) || d < doubleMin)
	{
		std::cerr << "The number is out of the double numbers range!" << std::endl;
		return false;
	}
	double number;
	stream.clear();
	stream.str(input);
	stream >> number;
	int castedToInt = static_cast<int> (number);
	char castedToChar = static_cast<char>(castedToInt);
	size_t fractionlDigitsNum = countFractionalDigits(input);
	printCahr(castedToInt, castedToChar);
	printInt(number, castedToInt);
	printFloat(number, static_cast<float>(number), fractionlDigitsNum);
	std::cout << std::fixed << std::setprecision(fractionlDigitsNum) << "double: " << number << std::endl;
	return true;
}

bool doNotConvert(std::string input)
{
	std::cout << input << ", is neither char, int, float or double!" << std::endl;
	return false;
}
