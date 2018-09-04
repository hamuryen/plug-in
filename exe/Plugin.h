#ifndef PLUGIN_H
#define PLUGIN_H

#include "IAnimal.h"

class Plugin
{
public:
	Plugin(std::string lib);
	~Plugin();
	void DoIt();

private:
	bool Load(std::string lib);
	void Destroy();

	HINSTANCE m_LibHandle;
	IAnimal *m_AnimalInstance;
};

#endif