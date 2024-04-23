/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:02:02 by anouri            #+#    #+#             */
/*   Updated: 2024/04/23 12:20:44 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Serializer.hpp"
#include <../incs/data.h>

Serializer::Serializer(/* args */)
{}

Serializer::~Serializer()
{}

Serializer::Serializer(const Serializer &src)
{
    (void)(src);
    // *this = src;
}

Serializer & Serializer::operator=(const Serializer &rhs)
{
    // if (this != &rhs)
    //     *this = rhs;
    (void)(rhs);
    return (*this);
}


//reinterprete cast is used to cast from a type to another completely different type

uintptr_t Serializer::serialize(Data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));   
}
Data* Serializer::deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data *>(raw)); 
}