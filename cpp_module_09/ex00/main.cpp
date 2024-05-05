/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:44:07 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/14 16:44:29 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::string db = "./data.csv";

	if (argc != 2)
	{
		std::cerr << "Input file name must be the only argument!" << std::endl;
		return INVALID_ARGUMENT;
	}

	try
	{
		BitcoinExchange::initData(db);
	}
	catch(std::exception &exception)
	{
		std::cerr << "Could not open file " << db << ": " << exception.what()  << std::endl;
	}
 
	try
	{
		BitcoinExchange::readFile(argv[1]);
	}
	catch(std::exception &exception)
	{
		std::cerr << "Could not open file " << argv[1] << ": " << exception.what()  << std::endl;
		return INVALID_ARGUMENT;
	}

	return 0;
}
