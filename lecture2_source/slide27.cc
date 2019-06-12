#include <iostream>
#include <string>
#include <vector>

typedef std::vector<std::string> StringVec;

int main(int argc, char* argv[]) {
	StringVec strings;
	strings.push_back("One");
	strings.push_back("Two");
	strings.push_back("Three");
	strings.push_back("Four");
	
	// Iterate through all elements, with explicit iterator type
	// Could use cbegin() and cend() here, since we're just reading
	for(StringVec::iterator it = strings.begin(); it != strings.end(); it++) {
		std::cout << *it << std::endl;
	}
	
	// Iterate through all elements, using auto (C++11 and higher only)
	// Could use cbegin() and cend() here, since we're just reading
	for(auto it = strings.begin(); it != strings.end(); it++) {
		std::cout << *it << std::endl;
	}

	// Iterate through all elements, using foreach loop (C++11 and higher only)
	// Note the const <type>& to avoid copying. What's auto here?
	for(const auto& val : strings) {
		std::cout << val << std::endl;		// No dereferencing needed!
	}

}