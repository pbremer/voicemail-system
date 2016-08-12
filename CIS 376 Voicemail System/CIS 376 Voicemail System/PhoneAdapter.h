#ifndef PHONE_ADAPTER_H
#define PHONE_ADAPTER_H

#include <string>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>

class PhoneAdapter {
private:
	std::istream& in;
	std::ostream& out;
public:
	PhoneAdapter(std::istream& is, std::ostream& os);
	~PhoneAdapter();
	int getUntil(const char* deliminers, std::string& val, bool include = false);
	int getNext(int num, std::string& val);
	void play(std::string audio);
};

#endif
