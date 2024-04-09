/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:04:43 by anouri            #+#    #+#             */
/*   Updated: 2024/04/09 18:00:26 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "Colors.hpp"
#include <iostream>
#include <string>
#include <exception>


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
        bool isChar(std::string str);
        bool isInt(std::string str);
        bool isFloat(std::string str);
        bool isDouble(std::string str);
        int getType(std::string str);
        void fromChar(std::string str);
        void fromInt(std::string str);
        void fromFloat(std::string str);
        void fromDouble(std::string str);
        class notAvalidArgument : std::exception
        {
           public:
                using exception::what;
                const char *what() const throw();
        }
};


#endif