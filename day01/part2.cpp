
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <algorithm>
#include "../colors.h/colors.h"

struct data {
	int			first;
	int			second;
	char		find;
	std::string	password;
};

static std::string readAndCalc(std::string fileName)
{
	std::string answer (COLOR_RED + fileName + COLOR_YELLOW " | " COLOR_GREEN);
	std::ifstream input (fileName);
	if (input.fail()) 
		return (answer + "unable to get answer!");
	std::list<data> passwords;
	std::string line;
	while (getline(input, line)) {
		data toAdd;
		toAdd.first = std::stoi(line) - 1;
		toAdd.second = std::stoi(line.substr(line.find("-") + 1)) - 1;
		toAdd.find = line[line.find(":") - 1];
		toAdd.password = line.substr(line.find(":") + 2);
		passwords.push_back(toAdd);
	}
	std::list<data>::iterator it;
	int count = 0;
	for (it = passwords.begin(); it != passwords.end(); it++) {
		if ((it->password[it->first] == it->find && it->password[it->second] != it->find) || (it->password[it->second] == it->find && it->password[it->first] != it->find))
			count++;
	}
	input.close();
	return (answer + std::to_string(count));
}

/*
** input files as arguments
*/

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "You need to specify an input file!" << std::endl;
	for (unsigned int i = 1; i < argc; i++)
		std::cout << readAndCalc(argv[i]) << std::endl;
}
