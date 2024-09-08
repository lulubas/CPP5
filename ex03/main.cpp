/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:33:18 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/07 10:49:53 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try
    {
    std::cout << "==============" << std::endl;
    std::cout << "CONSTRUCTORS" << std::endl;
    std::cout << "==============" << std::endl;

    Bureaucrat Alex("Alex", 100);
    Bureaucrat Sam ("Sam", 50);
    Bureaucrat Max ("Max", 1);

    std::cout << "==============" << std::endl;
    std::cout << "BUREAUCRATS" << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << Alex <<std::endl;
    std::cout << Sam << std::endl;
    std::cout << Max << std::endl;

    AForm* Form1 = new ShrubberyCreationForm("Treeeee"); //Sign 145 Exec 137
    AForm* Form2 = new RobotomyRequestForm("Formgobrrrr"); //Sign 72 Exec 45
    AForm* Form3 = new PresidentialPardonForm("Mrpresident"); //Sign 25 Exec 15

    std::cout << "==============" << std::endl;
    std::cout << "FORMS" << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << *Form1 <<std::endl;
    std::cout << *Form2 <<std::endl;
    std::cout << *Form3 <<std::endl;
    
    std::cout << "==============" << std::endl;
    std::cout << "SIGNING" << std::endl;
    std::cout << "==============" << std::endl;
    Alex.signForm(*Form1);
    Alex.executeForm(*Form1);
    
    Sam.signForm(*Form2);
    Sam.executeForm(*Form2);
    
    Max.signForm(*Form3);
    Max.executeForm(*Form3);
    std::cout << std::endl;
    
    std::cout << *Form1 <<std::endl;
    std::cout << *Form2 <<std::endl;
    std::cout << *Form3 <<std::endl;

    std::cout << "==============" << std::endl;
    std::cout << "DESTRUCTORS" << std::endl;
    std::cout << "==============" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}

