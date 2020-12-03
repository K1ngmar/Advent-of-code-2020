
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
	while (getline(input, line)) {
		slope.push_back(line);
	}
	size_t	count = 0;
	size_t	ans = 1;
	size_t	types[] = {1, 3, 5, 7, 1};
	size_t	down = 1;
	for (size_t i = 0; i < 5; i++) {
		size_t x = types[i];
		for (size_t y = down; y < slope.size(); y += down) {
			if (slope[y][x % slope[y].length()] == '#') {
				count++;
			}
			x += types[i];
		}
		ans *= count;
		count = 0;
		if (i == 3)
			down = 2;
	}
	input.close();
	return (answer + std::to_string(ans));
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
