/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:50:40 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/09 08:58:20 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150) {
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) :_name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    std::cout << "AForm parameterized constructor called" << std::endl;
}


AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &other) {

    std::cout << "AForm copy assignement operator called: can only copy sign state of the AForm" << std::endl;
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& stream, AForm& f) {
    stream << "Form " << f.getName() << ":" << std::endl;
    stream << "Min grade to sign=" << f.getSignGrade() << std::endl;
    stream << "Min grade to exec=" << f.getExecGrade() << std::endl;
    stream << "Is signed: " << (f.getSign() ? "Yes" : "No") << std::endl;
    return stream;
}

AForm::~AForm(){
    std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName(void) {
    return(_name);
}

void AForm::setSign(bool state) {
    _isSigned = state;
}

bool AForm::getSign(void) {
    return (_isSigned);
}

int AForm::getSignGrade(void) {
    return(_signGrade);
}

int AForm::getExecGrade(void) {
    return(_execGrade);
}

bool AForm::canSign(Bureaucrat& bc) {
    if (bc.getGrade() > _signGrade) {
        throw AForm::GradeTooLowException();
        return false;
    }
    return true;
}

bool AForm::canExecute(Bureaucrat& bc) {
    if(_isSigned == false) {
        throw AForm::DocumentNotSigned();
        return false;
    }       
    if (bc.getGrade() > _execGrade) {
        throw AForm::GradeTooLowException();
        return false;
    }
    return true;
}

const char* AForm::GradeTooLowException::what() const throw() {
    return("Grade of bureaucrat too low!");
};

const char* AForm::DocumentNotSigned::what() const throw() {
    return("The document is not signed!");
};