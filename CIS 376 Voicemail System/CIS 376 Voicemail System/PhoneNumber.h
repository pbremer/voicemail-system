#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H

#include <string>
#include <regex>

struct PhoneNumber
{
#define PHONE_REGEX std::regex("(\\+\\d{1,3}|\\d{0,3})?(\\(\\d{1,3}\\)|\\d{1,3}-?)\\d{3}-?\\d{4}(x\\d{4})?", std::regex_constants::ECMAScript|std::regex_constants::icase)
#define DEFAULT_COUNTRY_CODE "1"

	std::string countryCode, areaCode, localExchange, lineNumber, extension;
	std::string searchdir;

	static inline bool valid(std::string& phonenumber)
	{
		return std::regex_match(phonenumber, PHONE_REGEX);
	}

	static bool parse(std::string& phonenumber, PhoneNumber& val)
	{
		if (valid(phonenumber))
		{
			std::string stripped;
			bool extensionflag = false;
			for (std::string::iterator itr = phonenumber.begin(); itr < phonenumber.end(); itr++)
			{
				if (isdigit(*itr))
				{
					if (extensionflag)
					{
						val.extension += *itr;
					}
					else
					{
						stripped += *itr;
					}
				}
				else if (isalpha(*itr))
				{
					extensionflag = true;
				}
			}

			for (std::string::iterator itr = stripped.begin(); itr < stripped.end(); itr++)
			{
				// Line Number
				if (stripped.end() - itr < 5)
				{
					val.lineNumber += *itr;
				}
				// Local Exchange
				else if (stripped.end() - itr < 8)
				{
					val.localExchange += *itr;
				}
				// Area COde
				else if (stripped.end() - itr < 11)
				{
					val.areaCode += *itr;
				}
				// Country Code
				else
				{
					val.countryCode += *itr;
				}
			}

			if (val.countryCode.size() == 0)
			{
				val.countryCode = DEFAULT_COUNTRY_CODE;
			}

			return true;
		}
		else
		{
			return false;
		}
	}

};

#endif
