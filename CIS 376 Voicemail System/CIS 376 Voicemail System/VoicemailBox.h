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
	std::string& next();
	void remove();
	void save();
	void skip();
	void loadnew();
	void loadold();
	int count();
};

#endif