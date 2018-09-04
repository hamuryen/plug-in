#include "Cat.h"

Cat::Cat() 
{
    std::cout << "cat born!\n";
}

Cat::~Cat() 
{
    std::cout << "cat dead!\n\n";
}

std::string Cat::Sound()
{
    return std::string("meov");
}

int Cat::NumberOfLeg() 
{
    return 4;
}

void Cat::SayHello(std::string who) 
{
    std::cout << "hello " << who << std::endl;
}