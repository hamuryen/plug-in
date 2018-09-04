#include <vector>
#include "Plugin.h"

std::string Path()
{
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}

std::vector<std::string> ReadDirectory(const std::string &dir)
{
	std::vector<std::string> libs;
	std::string pattern(dir);
	pattern.append("\\*.dll");
	WIN32_FIND_DATA data;
	HANDLE hFind;
	if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE)
	{
		do
		{
			libs.push_back(dir + "\\" + data.cFileName);
		} while (FindNextFile(hFind, &data) != 0);
		FindClose(hFind);
	}
	return libs;
}

int main(int argc, char **argv)
{
	std::vector<std::string> libs = ReadDirectory(Path() + "\\plugin");
	for (auto l : libs)
	{
		Plugin p(l);
		p.DoIt();
	}

	std::cin.get();
	return 0;
}