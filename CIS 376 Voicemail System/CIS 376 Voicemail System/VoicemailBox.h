#ifndef VOICEMAILBOX_H
#define VOICEMAILBOX_H

#include <queue>
#include <string>
#include "boost/filesystem.hpp"
#include "PhoneNumber.h"

class VoicemailBox
{
private:
	std::queue<std::string> voicemails;
	PhoneNumber phone;
	bool existsFlag;
public:
	VoicemailBox(PhoneNumber& phoneNumber);
	~VoicemailBox();
	bool exists();
	bool hasNext();
	std::string next();
	void remove(std::string& path);
	void save(std::string& path);
	void loadnew();
	void loadold();
};

#endif