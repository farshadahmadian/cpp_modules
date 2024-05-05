/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:44:19 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/27 10:27:48 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_CPP
# define BITCOIN_EXCHANGE_CPP

#include <map>
#include <string>
#include <iostream>
#include <exception>
#include <fstream>
#include <algorithm>
#include <utility>
#include <ctime>
#include <cstring>
#include <sstream>
#include <iomanip>

class BitcoinExchange
{
	private:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);
		~BitcoinExchange(void);
	
		static std::map<std::string, std::string> _container;
		static std::map<std::string, std::string> _data;
		static int _year;
		static int _month;
		static int _day;
		static double _value;

		static void parseCurrentLine(std::string currentLine, bool &isFirstLine);
		static std::pair<std::string, std::string> splitByPipeChar(std::string currentLine);
		static void parseDate(std::string &date);
		static void parseValue(std::string value);
		static std::string trimLeft(std::string str);
		static std::string trimRight(std::string str);
		static std::pair<std::string, std::string> &trim(std::pair<std::string, std::string> &dateValuePair);
		static bool isMonthValid(int month);
		static bool isDayValid(struct tm time);
		static void updateDate(std::string year, std::string month, std::string day);
		static void updateValue(double convertedValue);

		static void storeDataBaseInContainer(std::string currentLine, bool isFirstLine);
		static std::string searchData(std::string date);

	public:
		static void readFile(std::string fileName);
		static double calculatePrice(std::pair<std::string, std::string> dateValuePair);
		static void initData(std::string dataFile);
		static void print(std::map<std::string, std::string> map);
		
		class InputException;
};

typedef enum e_error
{
	DEFAULT = -1,
	INVALID_ARGUMENT = 1,
	BAD_INPUT,
	VALUE_TOO_LARGE,
	INVALID_VALUE,
} t_error;

class BitcoinExchange::InputException : public std::exception
{
	public:
		InputException(void);
		InputException(t_error error);
		~InputException(void) throw();
		char const *what() const throw();

		static t_error _error;
};

#endif
