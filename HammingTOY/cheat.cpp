/*
 * cheat.cpp
 *
 *  Created on: 26 Jul 2018
 *      Author: rcyl
 */

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <iomanip>

#define PRINT(msg) std::cout << msg << std::endl;

void flipBits(const std::string & line);

int main(int argc,char *argv[]) {

	if (argc != 2) {
		PRINT("usage is cheat {input file}");
		return 1;
	}

	std::ifstream file(argv[1]);
	std::string line;

	PRINT("Input                                   Output")
	PRINT("----------------------------------      -------");

	while(1) {
		getline(file, line); //get input line
		if (line.find("FFFF") != std::string::npos) {
			PRINT("FFFF");
			PRINT("");
			PRINT("Note that your output will have one bit per line and it will");
			PRINT("be printed as 0000 or 0001.");
			return 0;
		}
		flipBits(line);
	}

	return 0;
}

void getTokens(const std::string &line, int M[4], int p[3]) {

	int temp[7];
	int i = 0;
	std::stringstream ss(line);
	std::string item;

	while(getline(ss, item, ' ') && i < 7) {
		temp[i++] = (int) std::stoi(item);
		std::cout << std::setfill('0') << std::setw(4) << temp[i - 1];
		std::cout << " ";
	}
	std::cout << "\t";

	std::copy(temp, temp + 4, M);
	std::copy(temp + 4, temp + 7, p);
}

void flipBits(const std::string &line) {

	int M[4];
	int p[3];

	getTokens(line, M, p);

	int mor = 0;
	int cmpi = 0;
	int failCount = 0;

	for(int i= 0; i < 4; i++)
		mor ^= M[i];

	for(int i = 2; i >=0 ; i--) {
		int pi = p[i];
		int shift = (1 << i);
		int temp = mor ^ M[2 - i];
		temp = (pi == temp);
		temp = temp << i;
		cmpi += temp;
	}

	for(int i = 2; i >= 0; i--) {
		int temp = (1 << i);
		if (temp == cmpi) {
			M[2 - i] = M[2 - i] ^ 1;
			break;
		}
	}
	if (cmpi == 0)
		M[3] = M[3] ^ 1;

	for(int i = 0; i < 4; i++) {
		std::cout << M[i];
		if (i == 3) std::cout << std::endl;
		else std::cout << " ";
	}
}

