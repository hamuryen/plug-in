#include "Bird.h"

Bird::Bird() 
{
    std::cout << "bird born!\n";
}

Bird::~Bird() 
{
    std::cout << "bird dead!\n\n";
}

std::string Bird::Sound()
{
    return std::string("cik");
}

int Bird::NumberOfLeg() 
{
    return 2;
}

void Bird::SayHello(std::string who) 
{
    std::cout << "hello " << who << std::endl;
}