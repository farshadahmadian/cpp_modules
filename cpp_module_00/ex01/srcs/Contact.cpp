/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:04:44 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/17 12:26:25 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int Contact::ContactIndex = 0;

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::GetFirstName(void) const
{
	return this->FirstName;
}

std::string Contact::GetLastName(void) const
{
	return this->LastName;
}

std::string Contact::GetNickName(void) const
{
	return this->NickName;
}

std::string Contact::GetPhoneNumber(void) const
{
	return this->PhoneNumber;
}

std::string Contact::GetDarkestSecret() const
{
	return this->DarkestSecret;
}

int Contact::GetContactIndex(void)
{
	return Contact::ContactIndex;
}

void Contact::SetFirstName(std::string firstName)
{
	this->FirstName = firstName;
}

void Contact::SetLastName(std::string lastName)
{
	this->LastName = lastName;
}

void Contact::SetNickName(std::string nickName)
{
	this->NickName = nickName;
}

void Contact::SetPhoneNumber(std::string phoneNumber)
{
	this->PhoneNumber = phoneNumber;
}

void Contact::SetDarkestSecret(std::string darkestSecret)
{
	this->DarkestSecret = darkestSecret;
}

int Contact::IncreaseContactIndex(void)
{
	Contact::ContactIndex++;
	return Contact::GetContactIndex();
}

void Contact::ResetContactIndex(void)
{
	Contact::ContactIndex = 0;
}
