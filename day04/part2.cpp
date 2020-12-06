
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include "../colors.h/colors.h"

static std::string readAndCalc(std::string fileName)
{
	std::string answer (COLOR_RED + fileName + COLOR_YELLOW " | " COLOR_GREEN);
	std::ifstream input (fileName);
	if (input.fail()) 
		return (answer + "unable to get answer!");
	std::vector<std::string> planeyboi;
	std::string line;
	while (getline(input, line)) {
		planeyboi.push_back(line);
	}
	std::vector<int> seatids;
	for (size_t i; i < planeyboi.size(); i++) {
		for (int j = 0; j < planeyboi[i].length(); j++) {
			if (planeyboi[i][j] == 'F' || planeyboi[i][j] == 'L')
				planeyboi[i][j] = '0';
			else
				planeyboi[i][j] = '1';
		}
		seatids.push_back(std::stoi(planeyboi[i], 0, 2));
	}
	size_t ans = 0;
	std::sort(seatids.begin(), seatids.end());
	for (int i = 1; i < seatids.size(); i++) {
		if (seatids[i - 1] + 1 != seatids[i]) {
			ans = seatids[i] - 1;
			std::cout << i << std::endl;
			break ;
		}
	}
	input.close();
	return (answer) + std::to_string(ans);
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
