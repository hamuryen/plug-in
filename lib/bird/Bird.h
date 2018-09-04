#ifndef BIRD_LIBRARY_H
#define BIRD_LIBRARY_H

#include "IAnimal.h"

class Bird : public IAnimal
{
public:
	Bird();
	~Bird();
	void Destroy()
	{
		delete this;
	};

	std::string Sound();
	int NumberOfLeg();
	void SayHello(std::string who);
};

extern "C" __declspec(dllexport) IAnimal *__cdecl CreateAnimal()
{
	return new Bird;
}

#endif