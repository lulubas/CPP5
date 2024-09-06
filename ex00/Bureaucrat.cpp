/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:01:43 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/06 14:38:08 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
    if (grade <= 0)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)  {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
    std::cout << "Bureaucrat copy assignement operator called" << std::endl;
    if (this != &other)
        _grade = other.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName(void) const {
    return(_name);
}

int Bureaucrat::getGrade(void) const {
    return(_grade);
}

void Bureaucrat::incrementGrade(void) {
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade(void) {
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat &other) {
    stream << other.getName() << ", bureaucrat grade " << other.getGrade();
    return stream;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}
