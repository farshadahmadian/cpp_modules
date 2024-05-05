/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:17:21 by fahmadia          #+#    #+#             */
/*   Updated: 2024/02/20 08:06:42 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
	Ice(void);
	Ice(std::string const &type);
	Ice(Ice const &ice);
	Ice &operator=(Ice const &ice);
	~Ice(void);
	AMateria *clone(void) const;
};

#endif
