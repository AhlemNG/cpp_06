/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:37:18 by anouri            #+#    #+#             */
/*   Updated: 2024/04/23 15:44:04 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <exception>
// #include <typeinfo> forbidden -_-

Base * generate(void)
{
    srand (time(NULL));
    int randNbr = rand() % 3;
    switch (randNbr)
    {
        case 0:{
            std::cout << "chose A randomly" << std::endl;
            return new A();
            break;
        }
        case 1:{
            std::cout << "chose B randomly" << std::endl;
            return new B();
            break;
        }
        case 2:{
            std::cout << "chose C randomly" << std::endl;
            return new C();
            break;
        }
        default:
            break;
    }
    return (NULL);
}

/*
TYPE& dynamic_cast<TYPE&> (object);
TYPE* dynamic_cast<TYPE*> (object);

The dynamic_cast keyword casts a datum from one pointer or reference type to another, 
performing a runtime check to ensure the validity of the cast.
If you attempt to cast to pointer to a type that is not a type of actual object, 
the result of the cast will be NULL. If you attempt to cast to reference to a type 
that is not a type of actual object, the cast will throw a bad_cast exception.*/

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Actual type is A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "Actual type is B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "Actual type is C" << std::endl;
}

void identify(Base& p)
{
    try {
            ((void)dynamic_cast<A&>(p));
            std::cout << "Actual type is A" << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "exception caught: " << e.what() << std::endl;
    }
    try {
            ((void)dynamic_cast<B&>(p));
            std::cout << "Actual type is B" << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "exception caught: " << e.what() << std::endl;
    }
    try {
            (void)(dynamic_cast<C&>(p));
            std::cout << "Actual type is C" << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "exception caught: " << e.what() << std::endl;
    }
}

int main()
{
    Base *base = generate();
    
    std::cout << "base = " << base << std::endl;
    identify(base);
    delete base;
    return (0);
}