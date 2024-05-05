/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:24:10 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/27 08:16:06 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <limits>

class ScalarConverter
{
private:
	ScalarConverter(void);
	ScalarConverter(ScalarConverter const &other);
	~ScalarConverter(void);
	ScalarConverter &operator=(ScalarConverter const &rhs);

public:
	static bool convert(std::string input);
};

#endif
