/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:13:26 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/17 10:16:51 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGA_PHONE_HPP
#define MEGA_PHONE_HPP

#include <cstdlib>
#include <climits>
#include <iomanip>
#include <iostream>
#include <string>
#include "PhoneBook.hpp"

std::string promptFirstName();
std::string promptLastName();
std::string promptNickName();
bool checkPhoneNumber(std::string phoneNumber);
std::string promptPhoneNumber();
std::string promptDarkestsecret();
void promptAdd(PhoneBook &phoneBook);

void drawTable();
void printContact(Contact contact, int i);
Contact modifyContact(Contact contact);
void showAllContacts(PhoneBook phoneBook);
void promptSearch(PhoneBook &phoneBook);
void drawHorizontalLine();
void displayInfo(const PhoneBook phoneBook, const int i);
bool checkIndex(std::string input, int &i);
bool promptIndex(const PhoneBook phoneBook);

std::string trim(std::string input, std::string toTrim);
bool myAtoi(const std::string str, int &num);

#endif
