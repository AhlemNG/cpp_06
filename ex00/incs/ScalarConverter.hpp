#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "Colors.hpp"
#include <iostream>
#include <string>


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

};

ScalarConverter::ScalarConverter(/* args */)
{
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string str)
{
    // std::cout << static_cast<char>(str) << std::endl;
    std::cout << static_cast<int>(str) << std::endl;
    // std::cout << (float)str << std::endl;
    // std::cout << (double)str << std::endl;
}
#endif