/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:39:11 by anouri            #+#    #+#             */
/*   Updated: 2024/04/09 18:06:34 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(/* args */)
{
    // std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    // std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    // *this= src;   
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{   
    // if (this != &rhs)
    //     *this = rhs;
    // return(*this);
}


bool ScalarConverter::isChar(std::string str)
{
    
}

bool ScalarConverter::isInt(std::string str)
{
 
}

bool ScalarConverter::isFloat(std::string str)
{

}

bool ScalarConverter::isDouble(std::string str)
{
    
}

int ScalarConverter::getType(std::string str)
{
    int sign = 1;
    int dbl = 0;
    int flt = 0;
    /*add a check for str[0]*/
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '-' || str[i] == '+')
        {
            // if (str == "-inf" || str == "-inff")
            if (str[i] == '-')
                sign *= -1;
            i++;
        }
        while (str[i])
        {
            while(isdigit(str[i]))
                i++;
            if (str[i] == '.')
            {
                if (!dbl)
                    dbl = 1;
                else 
                    throw (notAvalidArgument())
            }
            
        }
    }
}

void ScalarConverter::fromChar(std::string str)
{
    
}

void ScalarConverter::fromInt(std::string str)
{
    
}

void ScalarConverter::fromFloat(std::string str)
{
    
}

void ScalarConverter::fromDouble(std::string str)
{

}

void ScalarConverter::convert(std::string str)
{
    int type;
    try{
        type = getType(str);
        switch (type)
        {
            case 1:
                fromChar(str);
                break;   
            case 2:
                fromInt(str);
                break;   
            case 3:
                fromFloat(str);
                break;
            case 4:
                fromDouble(str);
                break;
            default:
                break; 
        }
    }
    catch(const std::exception  &e)
    {
        std::cerr << "exception: " << e.what() << std::endl;
    }
}


const char *ScalarConverter::notAvalidArgument::what() const throw()
{
    return ("not a valid argument");
}