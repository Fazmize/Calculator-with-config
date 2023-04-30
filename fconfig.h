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
		ConfigFile << "additon function = true\n";
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
	int itr = 0;

	conf.open("config.txt", std::ios::in);
	if (!conf) {
		std::cout << "not existing\n";
	}
	else {
		while (std::getline(conf, fileText)) {
			if (fileText.find("true") != std::string::npos) {
				data[itr] = 1;
				itr++;
			}
			else {
				itr++;
				std::cout << "loop";
			}
			
		}
		
	}
	conf.close();
	return data;
}