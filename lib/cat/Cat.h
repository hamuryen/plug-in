#ifndef CAT_LIBRARY_H
#define CAT_LIBRARY_H

#include "IAnimal.h"

class Cat : public IAnimal
{
public:
	Cat();
	~Cat();
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
	return new Cat;
}

#endif