/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:50:40 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/06 16:29:03 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Random target") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)  {
    std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("ShrubberyCreationForm", 145, 137), _target(other._target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {

    std::cout << "ShrubberyCreationForm copy assignement operator called: can only copy target of the ShrubberyCreationForm" << std::endl;
    if (this != &other) {
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    (void)executor;
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    outfile << "   *   " << std::endl;
    outfile << "  ***  " << std::endl;
    outfile << " ***** " << std::endl;
    outfile << "*******" << std::endl;
    outfile << "  |||  " << std::endl;
    outfile.close();
}
