/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:24:35 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/08 10:49:31 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}
Intern::Intern(std::string form, std::string target) {
    std::cout << "Intern parameterised constructor called" << std::endl;
}

Intern::Intern(const Intern& other) : {
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &other) {
    std::cout << "Intern copy assignement operator called" << std::endl;
    std::cout << "You can't copy an intern, there's already all the same!" << std::endl;
    return *this;
}

Intern::~Intern(){
    std::cout << "Intern destructor called" << std::endl;
}

const char* Intern::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}
