/*
 * avogrado.cpp
 *
 *  Created on: Aug 6, 2018
 *      Author: rcyl
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

/* meters per pixel */
#define MPP 	0.175e-6
#define T		297
#define N		9.135e-4
#define P		0.5e-6
#define R		8.31446

constexpr double pi() { return std::atan(1) * 4; }

int main() {

	std::string line;
	std::vector<double> v;
	double D = 0;
	double sum = 0;
	double k;

	while(std::getline(std::cin, line)) {
		if (line.length() != 0) {
			v.push_back(stod(line));
		}
	}

	for(unsigned int i = 0; i < v.size(); i++)
		sum += pow((v[i] * MPP), 2);

	D = sum / (2 * v.size());
	k =  (6 * pi() * D * N * P) / T;

	std::cout.precision(4);

	std::cout << "Boltzman = ";
	std::cout << std::scientific << k << std::endl;

	std::cout << "Avogadro = ";
	std::cout << std::scientific << R / k << std::endl;
}
