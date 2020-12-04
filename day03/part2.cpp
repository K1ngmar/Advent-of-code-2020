
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
		passport += " " + line;
		if (line == "" || input.eof()) {
			check.push_back(passport);
			passport = "";
		}
	}
	size_t ans = 0;
	for (size_t i = 0; i <= check.size(); i++) {
		size_t	pos;
		if ((pos = check[i].find("byr:") != std::string::npos) && std::atoi(check[i].substr(pos + 4).c_str()) >= 1920 && std::atoi(check[i].substr(pos + 4).c_str()) <= 2002 && (pos = check[i].find("iyr:") != std::string::npos) && std::stoi(check[i].substr(pos + 4)) >= 210 && std::stoi(check[i].substr(pos + 4)) <= 2020 && (pos = check[i].find("eyr:") != std::string::npos) && std::stoi(check[i].substr(pos + 4)) >= 2020 && std::stoi(check[i].substr(pos + 4)) <= 2030 && (pos = check[i].find("hgt:") != std::string::npos) && ((std::stoi(check[i].substr(pos + 4)) >= 150 && std::stoi(check[i].substr(pos + 4)) <= 193 && check[i].find("cm") == pos + 7) || (std::stoi(check[i].substr(pos + 4)) >= 59 && std::stoi(check[i].substr(pos + 4)) <= 76 && check[i].find("in") == pos + 6)) && (pos = check[i].find("hcl:#") != std::string::npos) && ((check[i][pos + 6] >= '0' && check[i][pos + 6] <= '9') || (check[i][pos + 6] >= 'a' && check[i][pos + 6] <= 'f')) && ((check[i][pos + 7] >= '0' && check[i][pos + 7] <= '9') || (check[i][pos + 7] >= 'a' && check[i][pos + 7] <= 'f')) && ((check[i][pos + 8] >= '0' && check[i][pos + 8] <= '9') || (check[i][pos + 8] >= 'a' && check[i][pos + 8] <= 'f')) && ((check[i][pos + 9] >= '0' && check[i][pos + 9] <= '9') || (check[i][pos + 9] >= 'a' && check[i][pos + 9] <= 'f')) && ((check[i][pos + 10] >= '0' && check[i][pos + 10] <= '9') || (check[i][pos + 10] >= 'a' && check[i][pos + 10] <= 'f')) && ((check[i][pos + 11] >= '0' && check[i][pos + 11] <= '9') || (check[i][pos + 11] >= 'a' && check[i][pos + 11] <= 'f')) && (pos = check[i].find("ecl:") != std::string::npos) && (check[i].find("amb", pos + 4) || check[i].find("blu", pos + 4) || check[i].find("brn", pos + 4) || check[i].find("gry", pos + 4) || check[i].find("grn", pos + 4) || check[i].find("hzl", pos + 4) || check[i].find("oth", pos + 4)) && (pos = check[i].find("pid:") != std::string::npos) && (check[i][pos + 4] >= '0' && check[i][pos + 4] <= '9') && (check[i][pos + 5] >= '0' && check[i][pos + 5] <= '9') && (check[i][pos + 6] >= '0' && check[i][pos + 6] <= '9') && (check[i][pos + 7] >= '0' && check[i][pos + 7] <= '9') && (check[i][pos + 8] >= '0' && check[i][pos + 8] <= '9') && (check[i][pos + 9] >= '0' && check[i][pos + 9] <= '9') && (check[i][pos + 10] >= '0' && check[i][pos + 10] <= '9') && (check[i][pos + 11] >= '0' && check[i][pos + 11] <= '9') && (check[i][pos + 12] >= '0' && check[i][pos + 12] <= '9') && (check[i][pos + 13] >= '0' && check[i][pos + 13] <= '9')) // I am pretty sure i will go to hell for this 😈
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
