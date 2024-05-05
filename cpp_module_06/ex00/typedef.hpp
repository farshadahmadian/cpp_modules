/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:24:14 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/27 08:16:16 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_DEF
# define TYPE_DEF

# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <limits>
# include <cmath>

typedef enum e_error
{
	WRONG_ARGUMENT = 1,
	NOT_CONVERTABLE,
} t_error;

typedef enum e_sign
{
	NONE = 0,
	NEGATIVE,
	POSITIVE,
} t_sign;

void printErrorMsg(std::string errorMessage);
std::string findType(std::string input, std::string const *types);
bool isTypeChar(std::string input);
bool isTypeInt(std::string input);
bool isTypeFloat(std::string input);
bool isTypeDouble(std::string input);
bool convertToChar(std::string input);
bool convertToInt(std::string input);
bool convertToFloat(std::string input);
bool convertToDouble(std::string input);
bool doNotConvert(std::string input);

#endif
