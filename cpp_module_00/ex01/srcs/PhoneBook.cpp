/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:04:51 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/16 14:33:00 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

Contact PhoneBook::GetContact(const int i) const
{
	return (this->Contacts[i]);
}

void PhoneBook::SetContact(const Contact contact, const int i)
{
	this->Contacts[i] = contact;
}
