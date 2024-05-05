/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:41:57 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/22 08:56:12 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void test1(void)
{
	Form form("form", 1, 1);
	Bureaucrat bureaucrat("bureaucrat", 10);

	form.beSigned(bureaucrat);
	std::cout << form;
	return;
}

void test2(void)
{
	Form form("form", 0, 1);

	Bureaucrat bureaucrat("bureaucrat", 10);

	bureaucrat.signForm(form);
	std::cout << form;
	return;
}

void test3(void)
{
	Form form("form", 10, 1);
	Bureaucrat bureaucrat("bureaucrat", 10);

	bureaucrat.signForm(form);
	std::cout << form;

	return;
}

int main(void)
{
	test1();
	// test2();
	// test3();
	return 0;
}