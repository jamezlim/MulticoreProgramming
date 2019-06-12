#include <iostream>
#include <string>
#include <map>

typedef std::map<std::string, std::string> StringStringMap;

int main(int argc, char* argv[]) {
	StringStringMap phones;
	phones["Sandra"] = "19175554321";
	phones["John"] = "12125551234";

	// What will the iterator thomas_phone contain?
	const StringStringMap::iterator thomas_phone = phones.find("Thomas");
	
	if (thomas_phone == phones.end()) {
		std::cout << "'Thomas' was not found in phones" << std::endl;
	} else {
		std::cout << "The phone number for " << thomas_phone->first << " is "
		          << thomas_phone->second << std::endl;
	}

	// What will the sandra_phone contain?
	// Note the use of the C++11 feature "auto". What type does this equate to? Why?
	const auto sandra_phone = phones.find("Sandra");
	
	if (sandra_phone == phones.end()) {
		std::cout << "'Sandra' was not found in phones" << std::endl;
	} else {
		std::cout << "The phone number for " << sandra_phone->first << " is "
		          << sandra_phone->second << std::endl;
	}
}
