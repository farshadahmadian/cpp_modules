/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:52:39 by fahmadia          #+#    #+#             */
/*   Updated: 2024/02/26 10:08:25 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string _type;

public:
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(AMateria const &materia);
	AMateria &operator=(AMateria const &materia);
	virtual ~AMateria(void);
	std::string const &getType() const;
	virtual AMateria *clone(void) const = 0;
	virtual void use(ICharacter &target);
	void setType(std::string const &type);
};

#endif
