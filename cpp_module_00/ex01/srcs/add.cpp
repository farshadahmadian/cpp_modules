/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:11:06 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/17 09:24:23 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"

std::string promptMessage(std::string attribute)
{
	std::string input = "";
	std::string trimmed = "";
	while (trimmed.empty())
	{
		std::cout << "Please enter the " + attribute << ':';
		getline(std::cin, input);
		trimmed = trim(input, " \t");
		if (std::cin.fail())
			exit(1);
	}
	return input;
}

std::string promptFirstName()
{
	std::string firstName = promptMessage("first name");
	return firstName;
}

std::string promptLastName()
{
	std::string lastName = promptMessage("last name");
	return lastName;
}

std::string promptNickName()
{
	std::string nickname = promptMessage("nickname");
	return nickname;
}

bool checkPhoneNumber(std::string phoneNumber)
{
	bool isFirstPlus = phoneNumber[0] == '+';
	if (!(isdigit(phoneNumber[0]) || isFirstPlus))
		return false;
	for (size_t i = 1; i < phoneNumber.size(); i++)
	{
		if (!isdigit(phoneNumber[i]))
		{
			std::cout << "Invalid phone number!" << std::endl;
			return false;
		}
	}
	return true;
}

std::string promptPhoneNumber()
{
	bool isValid = false;
	std::string phoneNumber = "";
	while (!isValid)
	{
		std::cout << "Please enter the phoneNumber: ";
		getline(std::cin, phoneNumber);
		if (std::cin.fail())
			exit(1);
		isValid = checkPhoneNumber(phoneNumber);
	}
	return phoneNumber;
}

std::string promptDarkestsecret()
{
	std::string darkestSecret = promptMessage("darkest secret");
	return darkestSecret;
}

void promptAdd(PhoneBook &phoneBook)
{
	Contact contact;
	int i = Contact::GetContactIndex();
	if (i > 7)
	{
		Contact::ResetContactIndex();
		i = Contact::GetContactIndex();
	}
	contact.SetFirstName(promptFirstName());
	contact.SetLastName(promptLastName());
	contact.SetNickName(promptNickName());
	contact.SetPhoneNumber(promptPhoneNumber());
	contact.SetDarkestSecret(promptDarkestsecret());
	phoneBook.SetContact(contact, i);
	Contact::IncreaseContactIndex();
}
