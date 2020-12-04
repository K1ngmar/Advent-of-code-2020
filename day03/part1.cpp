
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
	std::vector<std::string> check;
	std::string line;
	std::string	passport("");
	while (getline(input, line)) {
		if (line == "") {
			check.push_back(passport);
			passport = "";
		}
		else
			passport += " " + line;
	}
	passport += " " + line;
	check.push_back(passport);
	size_t ans = 0;
	for (size_t i = 0; i <= check.size(); i++) {
		if (check[i].find("byr:") != std::string::npos && check[i].find("iyr:") != std::string::npos && check[i].find("eyr:") != std::string::npos && check[i].find("hgt:") != std::string::npos && check[i].find("hcl:") != std::string::npos && check[i].find("ecl:") != std::string::npos && check[i].find("pid:") != std::string::npos) // WHAT ARE YOU LOOKING AT PUNK!
			ans++;
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
