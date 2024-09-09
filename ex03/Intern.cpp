/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:24:35 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/08 12:42:17 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const Intern::formArray Intern::_formArray[3] = {
    {"presidential", &Intern::_newPresidentialPardonForm},
    {"robotomy", &Intern::_newRobotomyRequestForm},
    {"shrubbery", &Intern::_newShrubberyCreationForm}
};

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other;
}

Intern& Intern::operator=(const Intern &other) {
    std::cout << "Intern copy assignement operator called" << std::endl;
    std::cout << "You can't copy an intern, there's already all the same!" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern(){
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(std::string form, std::string target) {
    int i;
    for (i = 0; i < 3; i++) {
        if (form.find(_formArray[i].formName) != std::string::npos)
            return(this->*_formArray[i].fct)(target);
    }
    throw Intern::FormDoesNotExist();
    return (NULL);
}

AForm* Intern::_newPresidentialPardonForm(std::string target) {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::_newRobotomyRequestForm(std::string target) {
    return (new RobotomyRequestForm(target));
}

AForm* Intern::_newShrubberyCreationForm(std::string target) {
    return (new ShrubberyCreationForm(target));
}

const char* Intern::FormDoesNotExist::what() const throw() {
    return "Intern could not find this form type!";
}
