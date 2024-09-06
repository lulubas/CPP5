/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:33:18 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/06 17:58:46 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try
    {
    std::cout << "==============" << std::endl;
    std::cout << "CONSTRUCTORS" << std::endl;
    std::cout << "==============" << std::endl;

    Bureaucrat Alex("Alex", 138);
    Bureaucrat Sam ("Sam", 100);

    std::cout << "==============" << std::endl;
    std::cout << "BUREAUCRATS" << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << Alex <<std::endl;
    std::cout << Sam << std::endl;

    AForm* Form1 = new ShrubberyCreationForm();

    std::cout << "==============" << std::endl;
    std::cout << "FORMS" << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << *Form1 <<std::endl;
    
    std::cout << "==============" << std::endl;
    std::cout << "SIGNING" << std::endl;
    std::cout << "==============" << std::endl;
    Alex.signForm(*Form1);
    Alex.executeForm(*Form1);
    std::cout << std::endl;
    
    std::cout << *Form1 <<std::endl;

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

