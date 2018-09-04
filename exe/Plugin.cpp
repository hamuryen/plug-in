#include "Plugin.h"

Plugin::Plugin(std::string lib) :
	m_LibHandle(nullptr),
	m_AnimalInstance(nullptr)
{
	if (!Load(lib))
		std::cerr << "An error occurred, " << lib << std::endl;
}

Plugin::~Plugin()
{
	Destroy();
}

bool Plugin::Load(std::string lib)
{
	m_LibHandle = LoadLibrary(TEXT(lib.c_str()));
	if (m_LibHandle == nullptr)
	{
		std::cerr << "Unable to load lib: " << lib << std::endl;
		return false;
	}
	std::cout << lib << " loaded!" << std::endl;

	AnimalFactory animal = reinterpret_cast<AnimalFactory>(GetProcAddress(m_LibHandle, "CreateAnimal"));
	if (animal == nullptr)
	{
		std::cerr << "Unable to load CreateAnimal method from lib: " << lib << std::endl;
		FreeLibrary(m_LibHandle);
		return false;
	}

	m_AnimalInstance = animal();
}

void Plugin::Destroy()
{
	if (m_AnimalInstance != nullptr)
		m_AnimalInstance->Destroy();
	if (m_LibHandle != nullptr)
		FreeLibrary(m_LibHandle);
}

void Plugin::DoIt()
{
	if (m_AnimalInstance != nullptr)
	{
		std::cout << "sound: " << m_AnimalInstance->Sound() << std::endl;
		std::cout << "number of leg: " << m_AnimalInstance->NumberOfLeg() << std::endl;
		m_AnimalInstance->SayHello("burak");
	}
}