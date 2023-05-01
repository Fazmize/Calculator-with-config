#include <fstream>
#include <iostream>
#include <string>


//This function generates config file
void confgen() {
	std::fstream ConfigFile;
	ConfigFile.open("config.txt", std::ios::out);

	if (!ConfigFile) {
		std::cout << "not created\n";
	}
	else {
		ConfigFile << "addition function = true\n";
		ConfigFile << "subtraction function = true\n";
		ConfigFile << "multiplication function = true\n";
		ConfigFile << "division function = true";
	}

	ConfigFile.close();
}


//This function is responsible for reading and passing the array to main
int* confread() {

	std::fstream conf;
	std::string fileText;
	static int data[4];
	std::string line[4];
	int itr = 0;

	conf.open("config.txt", std::ios::in);
	if (!conf) {
		std::cout << "not existing\n";
	}
	else {

		//Checks config for true and inputs value 1 or 0 into data array
		while (std::getline(conf, fileText)) {
			line[itr] = fileText;

			itr++;

		}
		data[0] = (line[0] == "addition function = true") ? 1 : 0;
		data[1] = (line[1] == "subtraction function = true") ? 1 : 0;
		data[2] = (line[2] == "multiplication function = true") ? 1 : 0;
		data[3] = (line[3] == "division function = true") ? 1 : 0;

	}

	conf.close();
	return data;
}

class sPtr {
	int* ptr;
public:
	explicit sPtr(int* p = NULL) { ptr = p; }

	~sPtr() { delete (ptr); }

	int& operator*() { return *ptr; }
};