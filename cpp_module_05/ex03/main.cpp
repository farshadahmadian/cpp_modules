/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:49:28 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/22 09:17:00 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void test1(Intern intern)
{
	Bureaucrat bureaucrat("bureaucrat", 1);
	AForm *createdForm = intern.makeForm("robotomy request", "Bender");

	createdForm->beSigned(bureaucrat);
	createdForm->execute(bureaucrat);
	std::cout << *createdForm;
	delete createdForm;
}

void test2(Intern intern)
{
	Bureaucrat bureaucrat("bureaucrat", 1);
	AForm *createdForm = intern.makeForm("shrubbery creation", "park");

	bureaucrat.signForm(*createdForm);
	bureaucrat.executeForm(*createdForm);
	std::cout << *createdForm;
	delete createdForm;
}

void test3(Intern intern)
{
	Bureaucrat bureaucrat("bureaucrat", 1);
	AForm *createdForm = intern.makeForm("presidential pardon", "John Doe");

	bureaucrat.signForm(*createdForm);
	bureaucrat.executeForm(*createdForm);
	std::cout << *createdForm;
	delete createdForm;
}

void test4(Intern intern)
{
	intern.makeForm("unknown", "target");
}

int main()
{
	Intern intern;

	test1(intern);
	// test2(intern);
	// test3(intern);
	// test4(intern);
	
	return 0;
}

