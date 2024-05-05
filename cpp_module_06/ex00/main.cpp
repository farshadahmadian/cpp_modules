/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:36:54 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/27 14:31:36 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "typedef.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printErrorMsg("One Argument is needed!");
		return WRONG_ARGUMENT;
	}
	bool result = ScalarConverter::convert(argv[1]);
	if (!result)
		return NOT_CONVERTABLE;

	return 0;
}
