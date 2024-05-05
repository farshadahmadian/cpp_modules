/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:42:24 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/21 13:07:38 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat
{
private:

	std::string const _name;
	unsigned int _grade;
	static unsigned int _minGrade;
	static unsigned int _maxGrade;
	class GradeTooHighException;
	class GradeTooLowException;
	class AssignmentException;

public:

	Bureaucrat(void);
	Bureaucrat(std::string const name, unsigned int grade);
	Bureaucrat(Bureaucrat const &bureaucrat);
	Bureaucrat &operator=(Bureaucrat const &rhs);
	~Bureaucrat(void);

	std::string const getName(void) const;
	unsigned int getGrade(void) const;

	Bureaucrat &operator++(void);
	Bureaucrat operator++(int a);
	Bureaucrat &operator--(void);
	Bureaucrat operator--(int a);
};

class Bureaucrat::GradeTooHighException : public std::exception
{
public:

	char const *what() const throw();
	~GradeTooHighException(void) throw();
	GradeTooHighException(void);
	GradeTooHighException(GradeTooHighException const &gradeTooHighException);
};

class Bureaucrat::GradeTooLowException : public std::exception
{
public:

	char const *what() const throw();
	~GradeTooLowException(void) throw();
};

class Bureaucrat::AssignmentException : public std::exception
{
public:

	char const *what() const throw();
	~AssignmentException(void) throw();
};

std::ostream &operator<<(std::ostream &cout, Bureaucrat const &bureaucrat);

#endif
