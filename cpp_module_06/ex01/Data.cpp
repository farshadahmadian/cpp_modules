/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:24:03 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/26 14:39:57 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : _intData(-6), _uIntData(25)
{
	return;
}
Data::Data(Data const &other)
{
	*this = other;
}

Data::~Data(void)
{
	return;
}

Data &Data::operator=(Data const &rhs)
{
	if (this != &rhs)
	{
		this->_intData = rhs._intData;
		this->_uIntData = rhs._uIntData;
	}
	return *this;
}

int Data::getIntData(void) const
{
	return this->_intData;
}

int Data::getuIntData(void) const
{
	return this->_uIntData;
}

std::ostream &operator<<(std::ostream &cout, Data const &data)
{
	std::cout << data.getIntData() << std::endl;
	std::cout << data.getuIntData() << std::endl;
	return cout;
}
