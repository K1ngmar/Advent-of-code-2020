
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "../colors.h/colors.h"

static std::string readAndCalc(std::string fileName)
{
	std::string answer (COLOR_RED + fileName + COLOR_YELLOW " | " COLOR_GREEN);
	std::ifstream input (fileName);
	if (input.fail()) 
		return (answer + "unable to get answer!");
	std::vector<std::string> slope;
	std::string line;
	size_t		count = 0;
	while (getline(input, line)) {
		slope.push_back(line);
	}
	size_t x = 3;
	for (size_t y = 1; y < slope.size(); y++) {
		if (slope[y][x % slope[y].length()] == '#')
			count++;
		x += 3;
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
