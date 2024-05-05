/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:05:44 by fahmadia          #+#    #+#             */
/*   Updated: 2024/02/26 15:24:54 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_materias[4];
	void deleteCurrentMaterias(void);
	void copyMaterias(MateriaSource const &materiaSource);
	AMateria **findFirstEmptySlot(void);
	AMateria *findMateriaWithType(std::string const &type);

public:
	MateriaSource(void);
	MateriaSource(MateriaSource const &materiaSource);
	MateriaSource &operator=(MateriaSource const &materiaSource);
	~MateriaSource(void);
	void learnMateria(AMateria *materia, bool isOnHeap);
	AMateria *createMateria(std::string const &type);
};

#endif
