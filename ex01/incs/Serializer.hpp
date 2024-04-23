/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:32:20 by anouri            #+#    #+#             */
/*   Updated: 2024/04/23 12:18:55 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALISER_HPP
#define SERIALISER_HPP

#include "Colors.hpp"
#include <stdint.h>
#include <data.h>
#include <iostream>

class Serializer
{
    private:
        /* data */
    public:
        Serializer(/* args */);
        ~Serializer();
        Serializer(const Serializer &src);
        Serializer & operator=(const Serializer &rhs);
       static uintptr_t serialize(Data* ptr);
       static Data* deserialize(uintptr_t raw);
    };

   

#endif