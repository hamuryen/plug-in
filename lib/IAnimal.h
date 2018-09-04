#ifndef ANIMAL_LIBRARY_H
#define ANIMAL_LIBRARY_H

#include <string>
#include <iostream>
#include <windows.h>

class IAnimal {
public:
    virtual ~IAnimal() {};
    virtual void Destroy() = 0;
    virtual std::string Sound() = 0;
    virtual int NumberOfLeg() = 0;
    virtual void SayHello(std::string who) = 0;
};

typedef IAnimal* (__cdecl *AnimalFactory)();

#endif