/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:50:06 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/06 16:29:17 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include"Bureaucrat.hpp"

#include<string>
#include<iostream>
#include<ostream>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;
        
    public:
        AForm();
        AForm(std::string name, int signGrade, int execGrade);
        AForm(const AForm &other);
        AForm& operator=(const AForm &other);
        ~AForm();

        std::string getName(void);
        void setSign(bool state);
        bool getSign(void);
        int getSignGrade(void);
        int getExecGrade(void);
        bool canSign(Bureaucrat& bc);
        bool canExecute(Bureaucrat& bc);
        
        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };  

        class DocumentNotSigned : public std::exception {
            public:
                const char* what() const throw();
        };  
};

std::ostream& operator<<(std::ostream& stream, AForm &f);

#endif