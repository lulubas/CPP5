/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:50:40 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/06 16:29:03 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("random_target") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)  {
    std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", 72, 45), _target(other._target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {

    std::cout << "RobotomyRequestForm copy assignement operator called: can only copy target of the RobotomyRequestForm" << std::endl;
    if (this != &other) {
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    (void)executor;
    std::cout << "Bzzzzzz... *drilling noises*" << std::endl;
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int success = std::rand() % 2;
    if (success == 1)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else 
        std::cout << "The robotomy of " << _target << " has failed." << std::endl;
}