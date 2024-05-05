/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:45:10 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/27 10:34:43 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

t_error BitcoinExchange::InputException::_error = DEFAULT;

std::map<std::string, std::string> BitcoinExchange::_container = std::map<std::string, std::string>();
std::map<std::string, std::string> BitcoinExchange::_data = std::map<std::string, std::string>();
int BitcoinExchange::_year = -1;
int BitcoinExchange::_month = -1;
int BitcoinExchange::_day = -1;
double BitcoinExchange::_value = -1;

BitcoinExchange::InputException::InputException(void) : std::exception()
{
	return;
}

BitcoinExchange::InputException::InputException(t_error error) : std::exception()
{
	BitcoinExchange::InputException::_error = error;
	return;
}

BitcoinExchange::InputException::~InputException(void) throw()
{
	return;
}

char const *BitcoinExchange::InputException::what() const throw()
{
	return "Error: ";
}

void BitcoinExchange::storeDataBaseInContainer(std::string currentLine, bool isFirstLine)
{
	if (isFirstLine)
		return;
	size_t delimiterIndex = currentLine.find_first_of(',');
	std::string date = currentLine.substr(0, delimiterIndex);
	std::string value = currentLine.substr(delimiterIndex + 1, std::string::npos);
	BitcoinExchange::_data[date] = value;
}

void BitcoinExchange::initData(std::string dataFile)
{
	std::ifstream inputFileStream(dataFile.c_str(), std::ios::in);
	if (!inputFileStream.is_open())
		throw std::exception();
	try
	{
		bool isFirstLine = true;
		std::string currentLine = "";
		while (getline(inputFileStream, currentLine))
		{
			BitcoinExchange::storeDataBaseInContainer(currentLine, isFirstLine);
			currentLine = "";
			isFirstLine = false;
		}
		inputFileStream.close();
	}
	catch(std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(void)
{
	return;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	(void)other;
	return;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	(void)rhs;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
	return;
}

std::pair<std::string, std::string> BitcoinExchange::splitByPipeChar(std::string currentLine)
{
	std::pair<std::string, std::string> dateValuePair;
	size_t pipeIndex = currentLine.find_first_of('|');
	if (pipeIndex == std::string::npos)
		throw InputException(BAD_INPUT);
	std::string date = currentLine.substr(0, pipeIndex);
	std::string value = currentLine.substr(pipeIndex + 1, std::string::npos);
	dateValuePair.first = date;
	dateValuePair.second = value;
	return dateValuePair;
}

std::string BitcoinExchange::trimRight(std::string str)
{
	std::string trimmedRight = str;
	size_t lastNoneWSP = str.find_last_not_of(" 	");
	if (lastNoneWSP != std::string::npos)
	{
		trimmedRight = str.substr(0, lastNoneWSP + 1);
	}
	return trimmedRight;
}

std::string BitcoinExchange::trimLeft(std::string str)
{
	std::string trimmedLeft = str;
	size_t firstNoneWSP = str.find_first_not_of(" \t");
	if (firstNoneWSP != std::string::npos)
	{
		trimmedLeft = str.substr(firstNoneWSP, std::string::npos);
	}
	return trimmedLeft;
}

std::pair<std::string, std::string> &BitcoinExchange::trim(std::pair<std::string, std::string> &dateValuePair)
{
	std::string date = dateValuePair.first;
	std::string value = dateValuePair.second;
	
	std::string trimmedLeftDate = trimLeft(date);
	std::string trimmedDate = trimRight(trimmedLeftDate);

	std::string trimmedLeftValue = trimLeft(value);
	std::string trimmedValue = trimRight(trimmedLeftValue);

	dateValuePair.first = trimmedDate;
	dateValuePair.second = trimmedValue;
	return dateValuePair;
}

bool BitcoinExchange::isMonthValid(int month)
{
	if (month >= 1 && month <= 12)
		return true;
	else
		return false;
}

bool BitcoinExchange::isDayValid(struct tm time)
{
	int year = time.tm_year;
	int month = time.tm_mon;
	int day = time.tm_mday;

	if (day > 31 || day < 1)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2 && day > 29)
		return false;
	if (month == 2 && year % 4 != 0 && day > 28)
		return false;
	return true;
}

bool isFuture(struct tm currentTime, struct tm time)
{
	int currentYear = currentTime.tm_year + 1900;
	int currentMonth = currentTime.tm_mon + 1;
	int currentDay = currentTime.tm_mday;
	if (time.tm_year > currentYear)
		return true;
	else if (time.tm_year == currentYear && time.tm_mon > currentMonth)
		return true;
	else if (time.tm_year == currentYear && time.tm_mon == currentMonth && time.tm_mday > currentDay)
		return true;
	else
		return false;
}

bool isTooOld(std::tm time)
{
	std::tm oldestTime;

	int oldestYear = oldestTime.tm_year = 2009;
	int oldestMonth = oldestTime.tm_mon = 1;
	int oldestDay = oldestTime.tm_mday = 2;

	if (time.tm_year < oldestYear)
		return true;
	else if (time.tm_year == oldestYear && time.tm_mon < oldestMonth)
		return true;
	else if (time.tm_year == oldestYear && time.tm_mon == oldestMonth && time.tm_mday < oldestDay)
		return true;
	else 
		return false;
}

void BitcoinExchange::updateDate(std::string year, std::string month, std::string day)
{
	BitcoinExchange::_year = std::atoi(year.c_str());
	BitcoinExchange::_month = std::atoi(month.c_str());
	BitcoinExchange::_day = std::atoi(day.c_str());
}

void BitcoinExchange::updateValue(double convertedValue)
{
	BitcoinExchange::_value = convertedValue;
}

std::string normalizeDayOrMonth(std::string &dayOrMonth)
{
	if (dayOrMonth.length() == 1)
		dayOrMonth = '0' + dayOrMonth;
	return dayOrMonth;
}

void BitcoinExchange::parseDate(std::string &date)
{
	bool isValidChars = date.find_first_not_of("0123456789-") != std::string::npos ? false : true;
	size_t firstDashIndex = date.find_first_of('-');
	size_t lastDashIndex = date.find_last_of('-');
	bool isFirstDash = firstDashIndex != std::string::npos;
	bool isLastDash = lastDashIndex != std::string::npos && firstDashIndex != lastDashIndex;
	std::string year = date.substr(0, firstDashIndex);

	std::string month = date.substr(firstDashIndex + 1, lastDashIndex - firstDashIndex - 1);
	normalizeDayOrMonth(month);

	std::string day = date.substr(lastDashIndex + 1, std::string::npos);
	normalizeDayOrMonth(day);

	if (!isValidChars || !isFirstDash || !isLastDash || year.length() > 4 || month.length() != 2 || day.length() != 2)
		throw InputException(BAD_INPUT);
	
	struct tm time;
	time.tm_year = std::atoi(year.c_str());
	time.tm_mon = std::atoi(month.c_str());
	time.tm_mday = std::atoi(day.c_str());

	time_t now = std::time(NULL);
	std::tm *currentTime = localtime(&now);

	if (!isMonthValid(time.tm_mon) || !isDayValid(time) || isFuture(*currentTime, time) || isTooOld(time))
		throw InputException(BAD_INPUT);
	BitcoinExchange::updateDate(year, month, day);
	date = year + '-' + month + '-' + day;
}

void BitcoinExchange::parseValue(std::string value)
{
	size_t invalidCharIndex = value.find_first_not_of("0123456789.");
	size_t firstDotIndex = value.find_first_of('.');
	size_t lastDotIndex = value.find_last_of('.');

	if (invalidCharIndex != std::string::npos || firstDotIndex != lastDotIndex)
	{
		throw InputException(INVALID_VALUE);
	}

	float convertedValue = atof(value.c_str());
	if (convertedValue > 1000)
		throw InputException(VALUE_TOO_LARGE);
	updateValue(convertedValue);
}

void BitcoinExchange::parseCurrentLine(std::string currentLine, bool &isFirstLine)
{
	if (isFirstLine)
	{
		isFirstLine = false;
		return;
	}
	std::pair<std::string, std::string> dateValuePair;

	try
	{
		dateValuePair = splitByPipeChar(currentLine);
		trim(dateValuePair);

		parseDate(dateValuePair.first);
		parseValue(dateValuePair.second);
		BitcoinExchange::_container[dateValuePair.first] = dateValuePair.second;
		BitcoinExchange::calculatePrice(dateValuePair);
	}
	catch(InputException &exception)
	{
		if (BitcoinExchange::InputException::_error == BAD_INPUT)
			std::cerr << exception.what() << "bad input => " << (!dateValuePair.first.empty() ? dateValuePair.first : trimRight(trimLeft(currentLine))) << std::endl;
		else if (InputException::_error == VALUE_TOO_LARGE)
			std::cerr << exception.what() << "too large a number => " << dateValuePair.second << std::endl;
		else if (InputException::_error == INVALID_VALUE)
			std::cerr << exception.what() << "not a positive number => " << dateValuePair.second << std::endl;
	}
}

void BitcoinExchange::readFile(std::string fileName)
{
	std::ifstream inputFileStream(fileName.c_str(), std::ios::in);
	if (!inputFileStream.is_open())
		throw std::exception();
	try
	{
		bool isFirstLine = true;
		std::string currentLine = "";
		while (getline(inputFileStream, currentLine))
		{
			parseCurrentLine(currentLine, isFirstLine);
			currentLine = "";
			isFirstLine = false;
		}
		inputFileStream.close();
	}
	catch(std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}

std::string convertTimeToString(struct tm time)
{
	std::stringstream stream;

	stream << time.tm_mday;
	std::string day = stream.str();
	normalizeDayOrMonth(day);
	stream.clear();
	stream.str(std::string());

	stream << time.tm_mon;
	std::string month = stream.str();
	normalizeDayOrMonth(month);
	stream.clear();
	stream.str(std::string());

	stream << time.tm_year;
	std::string year = stream.str();
	stream.clear();
	stream.str("");

	std::string date = year + '-' + month + '-' + day;
	return date;
}

std::string decreaseDate(std::tm &time)
{
	std::string date = "";
	if (time.tm_mday - 1 > 0)
	{
		time.tm_mday--;
		date = convertTimeToString(time);
	}
	else if (time.tm_mday - 1 == 0 && time.tm_mon - 1 > 0)
	{
		time.tm_mday = 31;
		time.tm_mon--;
		date = convertTimeToString(time);
	}
	else if (time.tm_mday - 1 == 0 && time.tm_mon - 1 == 0 && time.tm_year - 1 >= 2009)
	{
		time.tm_mday = 31;
		time.tm_mon = 12;
		time.tm_year--;
		date = convertTimeToString(time);
	}
	else
	{
		throw BitcoinExchange::InputException(BAD_INPUT);
	}
	return date;
}

std::string BitcoinExchange::searchData(std::string date)
{
	std::string copy = date;
	std::string price = BitcoinExchange::_data[date];
	if (price != "")
	{
		return price;
	}
	
	struct tm time;
	time.tm_year = BitcoinExchange::_year;
	time.tm_mon = _month;
	time.tm_mday = _day;
	
	while (price == "")
	{
		try
		{
			date = decreaseDate(time);
		}
		catch(BitcoinExchange::InputException &exception)
		{
			std::cerr << exception.what() << "bad input => " << copy << std::endl;
			return "";
		}
		price = _data[date];
	}
	return price;
}

double BitcoinExchange::calculatePrice(std::pair<std::string, std::string> dateValuePair)
{
	std::string result = searchData(dateValuePair.first);
	double value = atof((dateValuePair.second).c_str());
	double price = atof(result.c_str());

	size_t valueDotIndex = dateValuePair.second.find_first_of('.');
	std::string valueDecimalPart = dateValuePair.second.substr(valueDotIndex + 1, std::string::npos);
	size_t valuePrecision = valueDotIndex == std::string::npos ? 0 : valueDecimalPart.length();

	size_t priceDotIndex = result.find_first_of('.');
	std::string priceDecimalPart = result.substr(priceDotIndex + 1, std::string::npos);
	size_t pricePrecision = priceDotIndex == std::string::npos ? 0 : priceDecimalPart.length();
	if (!result.empty())
	{
		std::cout << std::fixed << dateValuePair.first << " => " << std::setprecision(valuePrecision) << value << " x " << std::setprecision(pricePrecision) << price << " = " << std::setprecision(4) << value * price << std::endl;
		return price;
	}
	else
		throw InputException(BAD_INPUT);
}

void print(std::pair<std::string, std::string> dateValuePair)
{
	std::cout << dateValuePair.first << " | " << dateValuePair.second << std::endl;
}

void BitcoinExchange::print(std::map<std::string, std::string> map)
{
	std::cout << "PRINTING\n";
	std::for_each(map.begin(), map.end(), ::print);
}
