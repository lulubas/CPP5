/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:21:00 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/08 10:48:46 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
         
    public:
        Intern();
        Intern(std::string form, std::string target);
        Intern(const Intern &other);
        Intern& operator=(const Intern &other);
        ~Intern();

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif