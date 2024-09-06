/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:50:06 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/06 16:13:19 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include"Bureaucrat.hpp"

#include<string>
#include<iostream>
#include<ostream>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;
        
    public:
        Form();
        Form(std::string name, int signGrade, int execGrade);
        Form(const Form &other);
        Form& operator=(const Form &other);
        ~Form();

        std::string getName(void);
        void setSign(bool state);
        bool getSign(void);
        int getSignGrade(void);
        int getExecGrade(void);  
        
        void beSigned(Bureaucrat& bc); 

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };  
};

std::ostream& operator<<(std::ostream& stream, Form &f);

#endif