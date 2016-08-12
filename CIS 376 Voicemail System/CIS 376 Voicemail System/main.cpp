#include <iostream>

#include "PhoneAdapter.h"
#include "PhoneNumber.h"
#include "VoicemailBox.h"

PhoneAdapter phoneAdapter(std::cin, std::cout);
std::string datastorePath;

void setup();
// Rel 2: Remove and get phone number from phone system API
void intro(std::string& val);

int main(int argc, const char* argv[]) {

	setup();

	std::string input;

	while (true)
	{
		intro(input);
		PhoneNumber phoneNumber;
		if (PhoneNumber::parse(input, phoneNumber))
		{
			phoneNumber.searchdir = datastorePath;
			VoicemailBox vmailbox(phoneNumber);
			if (vmailbox.exists())
			{
				vmailbox.loadnew();
				while (vmailbox.hasNext())
				{
					std::string audio = vmailbox.next();
					phoneAdapter.play(audio);
					std::cout << "Get selection..." << std::endl;
				}

				std::cout << "No new voicemails" << std::endl;
				
				vmailbox.loadold();
				while (vmailbox.hasNext())
				{
					phoneAdapter.play(vmailbox.next());
					std::cout << "Get selection..." << std::endl;
				}

				std::cout << "No saved voicemails" << std::endl;
			}
			else
			{
				std::cout << "Does not exist" << std::endl;
			}
		}
		else
		{
			std::cout << input << " is not a valid phone number" << std::endl;
		}
	}
}

void setup()
{
	if (const char* env_var = std::getenv("VOICEMAIL_DIR"))
	{
		datastorePath = std::string(env_var);
	}
	else
	{
		datastorePath = std::string(std::getenv("USERPROFILE"));
	}
	datastorePath += "\\vm-sys\\vm";
}

void intro(std::string& val)
{
	std::cout << "Thank you for using the voicemail system" << std::endl;
	std::cout << "Please enter phone number: ";
	val.clear();
	int len = phoneAdapter.getUntil("#", val);
}