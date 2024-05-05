/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:18:14 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/16 14:30:08 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void printUpperCase(char **argv)
{
	std::string currentArg = "";

	while (*argv)
	{
		currentArg = (std::string)*argv;
		for (size_t i = 0; i < currentArg.size(); i++)
		{
			currentArg[i] = toupper(currentArg[i]);
			std::cout << currentArg[i];
		}
		argv++;
	}
}

int main(int argc, char **argv)
{
	std::string defaultMessage = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (argc == 1)
	{
		std::cout << defaultMessage << std::endl;
	}
	else
	{
		argv++;
		printUpperCase(argv);
		std::cout << std::endl;
	}
	return 0;
}
