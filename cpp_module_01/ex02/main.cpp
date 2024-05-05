/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:08:50 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/18 20:16:01 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string message = "HI THIS IS BRAIN";
	std::string *stringPTR = &message;
	std::string &stringREF = message;

	std::cout << "&message = " << &message << std::endl;
	std::cout << "stringPTR = " << stringPTR << std::endl;
	std::cout << "&stringREF = " << &stringREF << std::endl;

	std::cout << "message = " << message << std::endl;
	std::cout << "*stringPTR = " << *stringPTR << std::endl;
	std::cout << "stringREF = " << stringREF << std::endl;
	return 0;
}
