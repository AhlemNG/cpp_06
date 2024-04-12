#include "../incs/ScalarConverter.hpp"
#include "../incs/Colors.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else
        std::cerr << GREEN <<"Program requires one arguement" << RESET <<std::endl;
    return (0);
}