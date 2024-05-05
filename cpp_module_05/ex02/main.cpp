/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:49:28 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/22 09:01:28 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void test1(Bureaucrat bureaucrat)
{
	ShrubberyCreationForm shrubbery1("park");
	shrubbery1.beSigned(bureaucrat);
	shrubbery1.execute(bureaucrat);
	return;
}

void test2(Bureaucrat bureaucrat)
{
	ShrubberyCreationForm shrubbery1("./wrong/park");
	shrubbery1.beSigned(bureaucrat);
	shrubbery1.execute(bureaucrat);
	return;
}

void test3(Bureaucrat bureaucrat)
{
	RobotomyRequestForm form("form");
	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);
	return;
}

void test4(Bureaucrat bureaucrat)
{
	PresidentialPardonForm form("John Doe");
	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);
	return;
}

int main()
{
	Bureaucrat pro("Pro", 1);
	Bureaucrat intern("Intern", 150);

	test1(pro);
	// test1(intern);
	// test2(pro);
	// test3(pro);
	// test4(pro);
	return 0;
}

