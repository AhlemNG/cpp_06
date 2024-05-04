/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:04:43 by anouri            #+#    #+#             */
/*   Updated: 2024/05/04 12:06:17 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "Colors.hpp"
#include <string>
#include <cctype> //for isprint
#include <exception>
#include <cmath>
#include <limits>
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
// #include <cstdlib>
//commentaire

/*static method is a class level function that is 
associated with the class itself rather then with 
individual instances (objects of the class).
it is declared using the static keyword and we 
cans call it with the class name without the need
to create an object*/

class ScalarConverter
{
    private:
        /* data */
    public:
        ScalarConverter(/* args */); 
        virtual ~ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter & operator=(const ScalarConverter &rhs);

        static void convert(std::string str);
        static int getType(std::string str);
        static void fromChar(std::string str);
        static void fromInt(std::string str);
        static void fromFloat(std::string str);
        static void fromDouble(std::string str);
        static bool isPseudoLiteral(std::string str);
        class notAvalidArgument : std::exception
        {
           public:
                using exception::what;
                const char *what() const throw();
        };
};


#endif