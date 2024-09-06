/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:33:18 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/06 14:46:20 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try 
    {
        std::cout << "==============" << std::endl;
        std::cout << "CONSTRUCTORS" << std::endl;
        std::cout << "==============" << std::endl;

        Bureaucrat Alex("Alex", 100);
        Bureaucrat Sam ("Sam", 110);
        Bureaucrat Max ("Max", 2);
        Bureaucrat Joe ("Joe", 149);

        Alex.decrementGrade();
        Sam.incrementGrade();
        Max.incrementGrade();
        Joe.decrementGrade();

        std::cout << "==============" << std::endl;
        std::cout << "OUTPUT" << std::endl;
        std::cout << "==============" << std::endl;
        
        std::cout << Alex <<std::endl;
        std::cout << Sam << std::endl;
        std::cout << Max << std::endl;
        std::cout << Joe << std::endl;

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

