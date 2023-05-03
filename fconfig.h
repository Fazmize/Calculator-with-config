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
void confread(int ptr[]) {

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
		ptr[0] = (line[0] == "addition function = true") ? 1 : 0;
		ptr[1] = (line[1] == "subtraction function = true") ? 1 : 0;
		ptr[2] = (line[2] == "multiplication function = true") ? 1 : 0;
		ptr[3] = (line[3] == "division function = true") ? 1 : 0;

	}

	conf.close();
	//return data;
}
