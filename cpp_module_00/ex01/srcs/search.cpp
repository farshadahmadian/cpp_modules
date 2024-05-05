/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:21:35 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/17 09:26:06 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"

void drawHorizontalLine()
{
	std::string horizontalLine(45, '-');
	std::cout << horizontalLine << std::endl;
}

void drawTable()
{
	std::cout << '|' << std::setw(11) << std::right << "index|";
	std::cout << std::setw(11) << std::right << "first name|";
	std::cout << std::setw(11) << std::right << "last name|";
	std::cout << std::setw(11) << std::right << "nickname|" << std::endl;
	drawHorizontalLine();
}

void printContact(Contact contact, int i)
{
	std::cout << '|' << std::setw(10) << std::right << i;
	std::cout << '|' << std::setw(10) << std::right << contact.GetFirstName();
	std::cout << '|' << std::setw(10) << std::right << contact.GetLastName();
	std::cout << '|' << std::setw(10) << std::right << contact.GetNickName();
	std::cout << '|' << std::endl;
}

Contact modifyContact(Contact contact)
{
	std::string toTrim = " \t";
	std::string firstName = trim(contact.GetFirstName(), toTrim);
	std::string lastName = trim(contact.GetLastName(), toTrim);
	std::string nickname = trim(contact.GetNickName(), toTrim);

	if (firstName.size() > 10)
		firstName.erase(9, std::string::npos).append(1, '.');
	if (lastName.size() > 10)
		lastName.erase(9, std::string::npos).append(1, '.');
	if (nickname.size() > 10)
		nickname.erase(9, std::string::npos).append(1, '.');
	
	contact.SetFirstName(firstName);
	contact.SetLastName(lastName);
	contact.SetNickName(nickname);
	return contact;
}

void showAllContacts(PhoneBook phoneBook)
{
	for (int i = 0; i < 8; i++)
	{
		phoneBook.SetContact(modifyContact(phoneBook.GetContact(i)), i);
		printContact(phoneBook.GetContact(i), i);
	}
}

void displayInfo(const PhoneBook phoneBook, const int i)
{
	Contact contact;
	contact = phoneBook.GetContact(i);
	std::cout << "First Name = " << contact.GetFirstName() << std::endl;
	std::cout << "Last Name = " << contact.GetLastName() << std::endl;
	std::cout << "Nickname = " << contact.GetNickName() << std::endl;
	std::cout << "Phone Number = " << contact.GetPhoneNumber() << std::endl;
	std::cout << "Darkest Secret = " << contact.GetDarkestSecret() << std::endl;
}

bool checkIndex(std::string input, int &i)
{
	std::string toTrim = " \t";
	input = trim(input, toTrim);

		if (!myAtoi(input, i))
			return false;
	return true;
}

bool promptIndex(const PhoneBook phoneBook)
{
	int i = 0;
	std::string input;
	do
	{
		i = 0;
		std::cout << "Please enter the index of the contact you are searching for :" << std::endl;
		getline(std::cin, input);
		if (std::cin.fail())
			exit(1);
		if (!checkIndex(input, i))
		{
			std::cout << "Wrong input!" << std::endl;
			i = - 1;
			continue;
		}
		if (i > INT_MAX)
		{
			std::cout << "Too large input!!! Try from the beginning!" << std::endl;
			return false;
		}
		if (i < 0 || i > 7)
			std::cout << "Wrong input!" << std::endl;
	} while (!(i >= 0 && i <= 7));
	displayInfo(phoneBook, i);
	return true;
}

void promptSearch(PhoneBook &phoneBook)
{
	drawTable();
	showAllContacts(phoneBook);
}
