#include "PhoneAdapter.h"
#include <sstream>

#pragma comment(lib, "winmm.lib")

PhoneAdapter::PhoneAdapter(std::istream& is, std::ostream& os) : in(is), out(os)
{
	// Rel 2: Connect to input and output streams
};

PhoneAdapter::~PhoneAdapter()
{
	// Rel 2: close streams
}

int PhoneAdapter::getUntil(const char* deliminers, std::string& val, bool include)
{
	std::string delimstr = deliminers;
	char next;
	do
	{
		in.get(next);
		next = tolower(next);
		if (!isspace(next) || delimstr.find(next) != std::string::npos)
		{
			val += next;
		}
	} while (delimstr.find(next) == std::string::npos);

	if (!include)
	{
		val.pop_back();
	}

	return val.size();
}

int PhoneAdapter::getNext(int num, std::string& val)
{
	char next;

	for (int i = 0; i < num; i++) {
		in.get(next);
		next = tolower(next);
		if (isspace(next))
		{
			i--;
		}
		else
		{
			val += next;
		}
	}

	return val.size();
}

void PhoneAdapter::play(std::string file)
{
	// Rel 2: Replace method body to pipe audio data to output stream
	std::wstring temp(file.begin(), file.end());
	PlaySound(temp.c_str(), NULL, 0);
}