/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:05:12 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/16 09:39:18 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;
	static int ContactIndex;

public:
	Contact();
	~Contact();
	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetNickName() const;
	std::string GetPhoneNumber() const;
	std::string GetDarkestSecret() const;
	static int GetContactIndex(void);
	void SetFirstName(std::string);
	void SetLastName(std::string);
	void SetNickName(std::string);
	void SetPhoneNumber(std::string);
	void SetDarkestSecret(std::string);
	static int IncreaseContactIndex(void);
	static void ResetContactIndex(void);
};

#endif
