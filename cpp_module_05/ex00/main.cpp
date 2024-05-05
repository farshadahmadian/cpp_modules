/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:41:57 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/22 08:52:23 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test1(void)
{
	Bureaucrat bureaucrat1("bureaucrat1", 1);
	Bureaucrat bureaucrat2("bureaucrat2", 150);
	Bureaucrat bureaucrat3("bureaucrat3", 10);


	bureaucrat1 = bureaucrat2 = bureaucrat3; 
	bureaucrat1 = bureaucrat2;
	--(--bureaucrat1);
	std::cout << bureaucrat1.getGrade() << std::endl;
	std::cout << bureaucrat1;
	operator<<(std::cout, bureaucrat1);
	return;
}

void test2(void)
{
	Bureaucrat bureaucrat1("bureaucrat1", 0);
	Bureaucrat bureaucrat2("bureaucrat2", 151);
	std::cout << bureaucrat1;
	operator<<(std::cout, bureaucrat2);
	return;
}

void test3(void)
{
	Bureaucrat bureaucrat1("bureaucrat1", 3);
	++(++(++bureaucrat1));
	std::cout << bureaucrat1;
	
	Bureaucrat bureaucrat2("bureaucrat2", 149);
	--(--bureaucrat2);
	operator<<(std::cout, bureaucrat2);
	return;
}

int main(void)
{
	
	test1();
	// test2();
	// test3();
	return 0;
}
