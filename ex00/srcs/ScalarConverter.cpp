/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:39:11 by anouri            #+#    #+#             */
/*   Updated: 2024/04/12 17:18:44 by anouri           ###   ########.fr       */
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
    *this= src;   
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{   
    if (this != &rhs)
        *this = rhs;
    return(*this);
}


int ScalarConverter::getType(std::string str)
{
    bool points = false;
    // int dbl = 0;
    // int flt = 0;
    unsigned long i = 0;
    if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
        return (1);//char
    if (str[i] == '-' || str[i] == '+')
        i++;//nothing to do here
    while (str[i])
    {
        if (str[i] == '.')
        {
            if (points)
                throw(ScalarConverter::notAvalidArgument());
            points = true;
        }
        else if (str[i] == 'f' && i == str.length() - 1)
            return (3);//float
        else if (isdigit(str[i]) && points && i == str.length() - 1)
            return (4);//double
        else if (!isdigit(str[i]))
            throw(ScalarConverter::notAvalidArgument());
        else if (isdigit(str[i]) && !points && i == str.length() - 1)
            return (2); //int
        i++;
    }
    return(0);
}

void ScalarConverter::fromChar(std::string str)
{
    char c = static_cast<char>(str[0]);

    if (isprint(c))
        std::cout << "Char: " << c << std::endl;  
    else
        std::cout << "char: " << "Non displayable" << std::endl;  
    std::cout << "int: " << static_cast<int>(c) << std::endl;  
    std::cout << "float: " << static_cast<float>(c) << std::endl;  
    std::cout << "double: " << static_cast<double>(c) << std::endl;  

}

// static int str_to_int( std::string & s )
// {
//     int i;
//     std::istringstream(s) >> i;
//     return i;
// }


void ScalarConverter::fromInt(std::string str)
{
    char *pEnd;
	long int i = strtol(str.c_str(), &pEnd, 10);
    if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min()) // check for overfow
        throw(ScalarConverter::notAvalidArgument());
    if (isprint(static_cast<char>(i)))
        std::cout << "char: " << static_cast<char>(i) << std::endl;  
    else 
        std::cout << "char: " << "Non displayable" << std::endl;  
    std::cout << "int: " << static_cast<int>(i) << std::endl;  
    std::cout << "float: " << static_cast<float>(i) << std::endl;  
    std::cout << "double: " << static_cast<double>(i) << std::endl;  
    
}

// void ScalarConverter::fromFloat(std::string str)
// {
    
// }

// void ScalarConverter::fromDouble(std::string str)
// {

// }

void ScalarConverter::convert(std::string str)
{
    int type;
    try{
        type = getType(str);
        std::cout << "type is " << type << std::endl;
        switch (type)
        {
            case 1:
                fromChar(str);
                break;   
            case 2:
                fromInt(str);
                break;   
        //     case 3:
        //         fromFloat(str);
        //         break;
        //     case 4:
        //         fromDouble(str);
        //         break;
            default:
                break; 
        }
    }
    catch(const ScalarConverter::notAvalidArgument &e) // does not accept std::exception!
    {
        std::cerr << "exception: " << e.what() << std::endl;
    }
}


const char *ScalarConverter::notAvalidArgument::what() const throw()
{
    return ("not a valid argument");
}
