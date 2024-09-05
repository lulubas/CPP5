/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:01:53 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/05 17:49:14 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<string>
#include<iostream>
#include<ostream>
#include <stdexcept>

class Bureaucrat {
    private:
        const   std::string _name;
        int     _grade;
         
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);
        virtual ~Bureaucrat();

        std::string getName(void) const;
        int getGrade(void) const;
        
        void incrementGrade(void);
        void decrementGrade(void);

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream&, const Bureaucrat &other);

#endif