/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:01:53 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/06 17:41:44 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"

#include<string>
#include<iostream>
#include<ostream>
#include <stdexcept>

class AForm;

class Bureaucrat {
    private:
        const   std::string _name;
        int     _grade;
         
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName(void) const;
        int getGrade(void) const;
        
        void incrementGrade(void);
        void decrementGrade(void);

        void signForm(AForm& form); 
        void executeForm(AForm& form); 

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat &other);

#endif