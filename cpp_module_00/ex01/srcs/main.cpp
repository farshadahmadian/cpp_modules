/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:04:59 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/17 12:25:55 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"

bool promptMenu(bool &isExit, PhoneBook &phoneBook)
{
	std::string input = "";
	std::string toTrim = " \t";
	std::cout << "Please enter ADD, SEARCH, or EXIT:" << std::endl;

	getline(std::cin, input);
	if (std::cin.fail())
		return false;
	input = trim(input, toTrim);
	if (input.compare("ADD") == 0)
		promptAdd(phoneBook);
	else if (input.compare("SEARCH") == 0)
	{
		promptSearch(phoneBook);
		if (!promptIndex(phoneBook))
			return false;
	}
	else if (input.compare("EXIT") == 0)
	{
		isExit = true;
	}
	else
		std::cout << "Incorrect input!" << std::endl;
	return true;
}

int main(void)
{
	bool isExit = false;
	PhoneBook phoneBook;

	while (!isExit)
	{
		if (!promptMenu(isExit, phoneBook))
			return 1;
	}
	return 0;
}
