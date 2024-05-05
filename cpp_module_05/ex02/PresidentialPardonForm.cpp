/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 07:32:59 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/21 15:29:27 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Default Target", "Presidential Form", 25, 5)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, "Presidential Form", 25, 5)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other)
{
	*this = other;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return;
}

PresidentialPardonForm const &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	(void)rhs;
	return *this;
}

void PresidentialPardonForm::runExecution(Bureaucrat const &bureaucrat, std::string const &target) const
{
	std::cout << bureaucrat.getName() << " executed " << this->getName() << std::endl;
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
