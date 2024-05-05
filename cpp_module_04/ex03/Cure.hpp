/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:37:30 by fahmadia          #+#    #+#             */
/*   Updated: 2024/02/14 12:51:36 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(std::string const &type);
	Cure(Cure const &cure);
	Cure &operator=(Cure const &cure);
	~Cure(void);
	AMateria *clone(void) const;
};
