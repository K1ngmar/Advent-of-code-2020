
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <algorithm>
#include "../colors.h/colors.h"

struct data {
	int			min;
	int			max;
	char		find;
	std::string	password;
};

static std::string readAndCalc(std::string fileName)
{
	std::stringstream ss;
	ss << COLOR_RED << fileName << COLOR_YELLOW << " | " COLOR_GREEN "Unable to get answer!" <<  std::endl;
	std::string answer = ss.str();
	std::ifstream input (fileName);
	if (input.fail()) 
		return (answer);
	std::list<data> passwords;
	std::string line;
	while (getline(input, line)) {
		data toAdd;
		toAdd.min = std::stoi(line);
		toAdd.max = std::stoi(line.substr(line.find("-") + 1));
		toAdd.find = line[line.find(":") - 1];
		toAdd.password = line.substr(line.find(":") + 2);
		passwords.push_back(toAdd);
	}
	std::list<data>::iterator it;
	int count = 0;
	for (it = passwords.begin(); it != passwords.end(); it++) {
		int occur = std::count(it->password.begin(), it->password.end(), it->find);
		if (occur >= it->min && occur <= it->max)
			count++;
	}
	input.close();
	return (std::to_string(count));
	
}

/*
** input files as arguments
*/

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "You need to specify an input file!" << std::endl;
	for (unsigned int i = 1; i < argc; i++)
		std::cout << readAndCalc(argv[i]);
}
