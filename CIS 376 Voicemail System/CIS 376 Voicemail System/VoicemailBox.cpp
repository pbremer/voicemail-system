#include "VoicemailBox.h"
#include <iostream>

namespace fs = boost::filesystem;

VoicemailBox::VoicemailBox(PhoneNumber& phoneNumber)
{
	phone = phoneNumber;
	phone.searchdir += "\\" + phoneNumber.countryCode + "\\" + phoneNumber.areaCode
		+ "\\" + phoneNumber.localExchange + "\\" + phoneNumber.lineNumber;
	if (!phoneNumber.extension.empty())
	{
		phone.searchdir += "\\" + phoneNumber.extension;
	}

	phone.searchdir += "\\vm";
}

VoicemailBox::~VoicemailBox()
{
	while (hasNext())
	{
		voicemails.pop();
	}
}

bool VoicemailBox::hasNext()
{
	return voicemails.size() > 0;
}

std::string VoicemailBox::next()
{
	std::string retVal = voicemails.front();
	voicemails.pop();
	return retVal;
}

void VoicemailBox::remove(std::string& path)
{
	fs::remove(fs::path(path));
}

void VoicemailBox::save(std::string& path)
{
	// Rel 2
}

bool VoicemailBox::exists()
{
	return fs::is_directory(fs::path(phone.searchdir));
}

void VoicemailBox::loadnew()
{
	fs::path p(phone.searchdir + "\\new");
	if (fs::is_directory(p))
	{
		fs::directory_iterator end_itr;

		for (fs::directory_iterator itr(p); itr != end_itr; itr++)
		{
			if (fs::is_regular_file(itr->path()))
			{
				std::wstring ws(itr->path().c_str());
				voicemails.push(std::string(ws.begin(), ws.end()));
			}
		}
	}
}

void VoicemailBox::loadold()
{
	fs::path p(phone.searchdir + "\\old");
	if (fs::is_directory(p))
	{
		fs::directory_iterator end_itr;

		for (fs::directory_iterator itr(p); itr != end_itr; itr++)
		{
			if (fs::is_regular_file(itr->path()))
			{
				std::wstring ws(itr->path().c_str());
				voicemails.push(std::string(ws.begin(), ws.end()));
			}
		}
	}
}