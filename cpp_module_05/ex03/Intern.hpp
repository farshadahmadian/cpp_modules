/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:42:04 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/21 16:39:51 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <stdexcept>
#include "AForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(Intern const &other);
	~Intern(void);

	AForm *makeForm(std::string name, std::string target);

private:
	class UnknownForm;
	Intern &operator=(Intern const &rhs);

	AForm *createShrubberyForm(std::string target);
	AForm *createRobotomyForm(std::string target);
	AForm *createPresidentialForm(std::string target);
};

class Intern::UnknownForm : public std::exception
{
public:
	char const *what() const throw();
};

#endif
