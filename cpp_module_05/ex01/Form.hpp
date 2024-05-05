/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:31:24 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/21 12:57:23 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:

	std::string const _name;
	bool _isSigned;
	unsigned int const _requiredGradeToSign;
	unsigned int const _requiredGradeToExe;
	class GradeTooHighException;
	class GradeTooLowException;
	static unsigned int _minGrade;
	static unsigned int _maxGrade;

	Form &operator=(Form const &rhs);
	void checkGrades(unsigned int requiredGradeToSign, unsigned int requiredGradeToExe);

public:
	Form(void);
	Form(std::string name, unsigned int requiredGradeToSign, unsigned int requiredGradeToExe);
	Form(Form const &other);
	~Form(void);

	std::string const &getName(void) const;
	bool getIsSigned(void) const;
	unsigned int getRequiredGradeToSign(void) const;
	unsigned int getRequiredGradeToExe(void) const;

	void beSigned(Bureaucrat const &bureaucrat);
};

std::ostream &operator<<(std::ostream &cout, Form const &form);

#endif
