/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:39:11 by anouri            #+#    #+#             */
/*   Updated: 2024/04/23 11:28:02 by anouri           ###   ########.fr       */
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
        std::cout << "Char: " << "'" << c << "'" << std::endl;  
    else
        std::cout << "char: " << "Non displayable" << std::endl;  
    std::cout << "int: " << static_cast<int>(c) << std::endl;  
    std::cout << "float: " << static_cast<float>(c) << std::endl;  
    std::cout << "double: " << static_cast<double>(c) << std::endl;  

}


void ScalarConverter::fromInt(std::string str)
{
    char *pEnd;
	long int i = strtol(str.c_str(), &pEnd, 10);
    if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min()) // check for overfow
        throw(ScalarConverter::notAvalidArgument());
    if (i >= 0  && i <= 127 && isprint(static_cast<char>(i)))
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;  
    else 
        std::cout << "char: " << "Non displayable" << std::endl;  
    std::cout << "int: " << static_cast<int>(i) << std::endl;  
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl; 
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::fromFloat(std::string str)
{
    char *pEnd;
    float f;
    f = strtof(str.c_str(), &pEnd);
    if (*(pEnd + 1) != '\0')
		throw notAvalidArgument();
    //to char;
    if (!isprint(static_cast<char>(f)))
        std::cout << "char: " << "Non displayable" << std::endl;
    else 
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;  
    //to int
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    size_t pos = str.find(".");
    int precision = 0;
    if(pos != std::string::npos)
    {
        precision = str.length() - pos - 1;
    }
    if (precision < 6)
    {
        // to float
        std::cout << "float: " << f << "f" << std::endl; 
        //to double
        std::cout << "double: " << static_cast<double>(f)<< std::endl;
    }
    else
    {
        // to float
        std::cout  << std::fixed << std::setprecision(precision) <<"float: " << f << "f" << std::endl; 
        //to double
        std::cout <<  std::fixed << std::setprecision(precision) << "double: " << static_cast<double>(f) <<  std::endl;
    }
}
void ScalarConverter::fromDouble(std::string str)
{
    char *pEnd;
    double d;
    d = strtod(str.c_str(), &pEnd);
    if (pEnd == str.c_str())
    {
        throw std::invalid_argument("Invalid argument");
    }
    if (pEnd == str || *(pEnd) != '\0' || d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
		throw notAvalidArgument();
    
    //to char;
    if (!isprint(static_cast<char>(d)))
        std::cout << "char: " << "Non displayable" << std::endl;
    else 
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;  
    //to int
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    /*calculate precision*/
    size_t pos = str.find(".");
    int precision = 0;
    if(pos != std::string::npos)
    {
        precision = str.length() - pos - 1;
    }
    if (precision < 6)
    {
        // to float
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl; 
        //to double
        std::cout << "double: " << d <<  std::endl;
    }
    else
    {
        // to float
        std::cout  << std::fixed << std::setprecision(precision) <<"float: " << static_cast<float>(d) << "f" << std::endl; 
        //to double
        std::cout <<  std::fixed << std::setprecision(precision) << "double: " << (d) <<  std::endl;
    }
}

bool ScalarConverter::isPseudoLiteral(std::string str)
{
    (void)(str);
    char sign = '\0';
    const char *pseudo[] = {"nan" , "nanf", "-inf", "+inf", "inf", "-inff", "+inff", "inff"};
    for (int i = 0; i < 8; i++)
    {
        if (pseudo[i] == str)
        {
            if (str[0] == '-')
                sign = '-';
            if (i < 2)
            {
                std::cout << "char: " << "impossible" << std::endl;
                std::cout << "int: " << "impossible" << std::endl;
                std::cout  << "float: " <<"nanf" << std::endl; 
                std::cout <<  "double: " << "nan" <<  std::endl;
            }
            else
            {
                std::cout << "char: '" << "inpossible" << std::endl;
                std::cout << "int: " << "impossible" << std::endl;
                std::cout << "float: " << sign << "inf" << std::endl; 
                std::cout <<  "double: " << sign << "inff" <<  std::endl;
            }
            return (true);
        }
    }
    return(false);
}

void ScalarConverter::convert(std::string str)
{
    int type;
    if (isPseudoLiteral(str))
        return;
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
    catch(const ScalarConverter::notAvalidArgument &e) // does not accept std::exception!
    {
        std::cerr << "exception: " << e.what() << std::endl;
    }
}


const char *ScalarConverter::notAvalidArgument::what() const throw()
{
    return ("not a valid argument");
}
