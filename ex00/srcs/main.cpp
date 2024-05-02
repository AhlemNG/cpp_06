/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:35:41 by anouri            #+#    #+#             */
/*   Updated: 2024/05/02 13:35:44 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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