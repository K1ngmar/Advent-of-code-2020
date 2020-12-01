
#include <iostream>
#include <fstream>
#include <sstream>
#include "../../colors.h/colors.h"


static int lineCount(std::ifstream &file)
{
	std::string		line;
	unsigned int	count = 0;

	while (getline(file, line))
		count++;
	file.clear();
	file.seekg(0);
	return (count);
}

static unsigned int getAnswer(int *arr, unsigned int length)
{
	for (unsigned int i = 0; i < length - 2; i++) {
		for (unsigned int j = i + 1; j < length - 1; j++) {
			for (unsigned int k = j + 1; k < length; k++) {
				if (arr[i] + arr[j] + arr[k] == 2020) {
					std::cout << COLOR_RED << arr[i] << COLOR_YELLOW << " + " << COLOR_GREEN << arr[j] << COLOR_YELLOW << " + " << COLOR_PINK << arr[k] << std::endl;
					return (arr[i] * arr[j] * arr[k]);
				}
			}
		}
	}
	return (2020);
}

static std::string readAndCalc(std::string fileName)
{
	std::stringstream ss;
	ss << COLOR_RED << fileName << COLOR_YELLOW << " | " COLOR_GREEN "Unable to get answer!" <<  std::endl;
	std::string answer = ss.str();
	std::ifstream input (fileName);
	if (input.fail()) 
		return (answer);
	unsigned int	lc = lineCount(input);
	int				*arr = new int[lc];
	std::string		line;
	for (unsigned i = 0; i < lc; i++) {
		getline(input, line);
		arr[i] = std::stoi(line);
	}
	int thehekku = getAnswer(arr, lc);
	delete[] arr;
	input.close();
	if (thehekku == 2020)
		return (answer);
	std::cout << COLOR_YELLOW << thehekku << std::endl;
	return ("");
	
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
