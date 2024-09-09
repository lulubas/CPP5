/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:21:00 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/08 12:33:56 by lbastien         ###   ########.fr       */
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
        Intern(const Intern &other);
        Intern& operator=(const Intern &other);
        ~Intern();

        AForm* makeForm(std::string form, std::string target);
        AForm* _newPresidentialPardonForm(std::string target);
        AForm* _newRobotomyRequestForm(std::string target);
        AForm* _newShrubberyCreationForm(std::string target);

        struct formArray {
            std::string formName;
            AForm* (Intern::*fct)(std::string target);
        };

        class FormDoesNotExist : public std::exception {
            public:
                const char* what() const throw();
        };

        static const formArray _formArray[];
};

#endif