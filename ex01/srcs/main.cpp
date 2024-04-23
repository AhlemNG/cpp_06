/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:15:21 by anouri            #+#    #+#             */
/*   Updated: 2024/04/23 12:21:31 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Colors.hpp"
#include "../incs/Serializer.hpp"

int main()
{
    Data *data = new Data;
    data->i = 0;
    data->c = 'c';
    data->f = 02.0f;
    data->d = 2.02;
    
    uintptr_t ptr;
    
    ptr = Serializer::serialize(data);

    std::cout  << "uintptr_t = " << ptr << std::endl;
    
    delete (data);
    return (0);
}