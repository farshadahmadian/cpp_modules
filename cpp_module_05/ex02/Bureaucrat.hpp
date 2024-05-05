/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:42:24 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/21 12:59:51 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "AForm.hpp"
class AForm;

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
	Bureaucrat &operator=(Bureaucrat const &bureaucrat);
	~Bureaucrat(void);

	std::string const getName(void) const;
	unsigned int getGrade(void) const;

	Bureaucrat &operator++(void);
	Bureaucrat operator++(int a);
	Bureaucrat &operator--(void);
	Bureaucrat operator--(int a);

	void signForm(AForm &form);
	void executeForm(AForm const &form);
};


class Bureaucrat::AssignmentException : public std::exception
{
public:

	char const *what() const throw();
};

#endif
