/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:33:18 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/08 12:51:12 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    try
    {
    std::cout << "==============" << std::endl;
    std::cout << "CONSTRUCTORS" << std::endl;
    std::cout << "==============" << std::endl;

    Bureaucrat Alex("Alex", 100);
    Intern randomIntern;
    AForm* randomForm1 = randomIntern.makeForm("shrubbery presidential form", "randomTarget");
    AForm* randomForm2 = randomIntern.makeForm("form robotomytestform", "you");
    AForm* randomForm3 = randomIntern.makeForm("no exist this one", "me");

    std::cout << "==============" << std::endl;
    std::cout << "BUREAUCRATS " << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << Alex <<std::endl;
    

    std::cout << "==============" << std::endl;
    std::cout << "FORMS" << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << *randomForm1 <<std::endl;
    std::cout << *randomForm2 <<std::endl;
    std::cout << *randomForm3 <<std::endl;
    
    std::cout << "==============" << std::endl;
    std::cout << "SIGNING" << std::endl;
    std::cout << "==============" << std::endl;
    Alex.signForm(*randomForm1);
    Alex.executeForm(*randomForm1);
    Alex.signForm(*randomForm2);
    Alex.executeForm(*randomForm2);

    Alex.signForm(*randomForm3);
    Alex.executeForm(*randomForm3);
    
    std::cout << std::endl;
    
    std::cout << *randomForm1 <<std::endl;
    std::cout << *randomForm2 <<std::endl;
    std::cout << *randomForm3 <<std::endl;
    
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

