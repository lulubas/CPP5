/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:50:40 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/09 08:58:40 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) :_name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    std::cout << "Form parameterized constructor called" << std::endl;
}


Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &other) {

    std::cout << "Form copy assignement operator called: can only copy sign state of the form" << std::endl;
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& stream, Form& f) {
    stream << "Form " << f.getName() << ":" << std::endl;
    stream << "Min grade to sign=" << f.getSignGrade() << std::endl;
    stream << "Min grade to exec=" << f.getExecGrade() << std::endl;
    stream << "Is signed: " << (f.getSign() ? "Yes" : "No") << std::endl;
    return stream;
}

Form::~Form(){
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName(void) {
    return(_name);
}

void Form::setSign(bool state) {
    _isSigned = state;
}

bool Form::getSign(void) {
    return (_isSigned);
}

int Form::getSignGrade(void) {
    return(_signGrade);
}

int Form::getExecGrade(void) {
    return(_execGrade);
}

void Form::beSigned(Bureaucrat& bc) {
    if (bc.getGrade() > _signGrade)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

const char* Form::GradeTooLowException::what() const throw() {
    return("Grade of bureaucrat too low!");
};