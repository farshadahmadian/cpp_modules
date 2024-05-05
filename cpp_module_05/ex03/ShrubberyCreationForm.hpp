/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:53:41 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/21 15:23:21 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBEERY_CREATION_FORM_HPP
# define SHRUBEERY_CREATION_FORM_HPP

# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	~ShrubberyCreationForm(void);

private:
	class FileException;
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
	static void createAndOpenFile(std::string target);
	void runExecution(Bureaucrat const &bureaucrat, std::string const &target) const;
};

#endif
