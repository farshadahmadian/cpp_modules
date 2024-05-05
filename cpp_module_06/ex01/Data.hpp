/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:20:59 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/27 12:40:07 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

struct Data
{
public:
	Data(void);
	Data(Data const &other);
	~Data(void);
	Data &operator=(Data const &rhs);

	int getIntData(void) const;
	int getuIntData(void) const;

private:
	int _intData;
	unsigned int _uIntData;
};

std::ostream &operator<<(std::ostream &cout, Data const &data);
