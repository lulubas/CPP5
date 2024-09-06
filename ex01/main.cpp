/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:33:18 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/06 16:25:25 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try
    {
    std::cout << "==============" << std::endl;
    std::cout << "CONSTRUCTORS" << std::endl;
    std::cout << "==============" << std::endl;

    Bureaucrat Alex("Alex", 1);
    Bureaucrat Sam ("Sam", 100);

    std::cout << "==============" << std::endl;
    std::cout << "BUREAUCRATS" << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << Alex <<std::endl;
    std::cout << Sam << std::endl;

    Form Bill("Bill of rights", 150, 100);
    Form Constitution("The Constitiution", 50, 10);

    std::cout << "==============" << std::endl;
    std::cout << "FORMS" << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << Bill <<std::endl;
    std::cout << Constitution << std::endl;
    
    std::cout << "==============" << std::endl;
    std::cout << "SIGNING" << std::endl;
    std::cout << "==============" << std::endl;
    Alex.signForm(Bill);
    Sam.signForm(Constitution);
    std::cout << std::endl;
    
    std::cout << Bill <<std::endl;
    std::cout << Constitution << std::endl;

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

