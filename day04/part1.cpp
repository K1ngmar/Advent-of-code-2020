
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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
	size_t ans = 0;
	std::vector<int> seatids;
	for (size_t i; i < planeyboi.size(); i++) {
		std::pair<int, int> row;
		row.first = 0;
		row.second = 127;
		for (int j = 0; j < 7; j++) {
			if (planeyboi[i][j] == 'F')
				row.second -= (row.second - row.first) >> 1;
			else
				row.first += (row.second - row.first) >> 1;
		}
		ans = (row.first + (planeyboi[i][6] == 'B')) * 8;
		std::pair<int, int> col;
		col.first = 0;
		col.second = 7;
		for (int j = 7; j < 10; j++) {
			if (planeyboi[i][j] == 'L')
				col.second -= (col.second - col.first) >> 1;
			else
				col.first += (col.second - col.first) >> 1;
		}
		ans += (col.first + (planeyboi[i][9] == 'R'));
		seatids.push_back(ans);
	}
	ans = 0;
	for (int i = 0; i < seatids.size(); i++) {
		if (seatids[i] > ans)
			ans = seatids[i];
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
