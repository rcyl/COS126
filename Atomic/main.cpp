/*
 * main.cpp
 *
 *  Created on: Aug 5, 2018
 *      Author: rcyl
 */

#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <array>
#include "BeadFinder.h"

#define BT

#ifdef BF

int main(int argc, char *argv[]) {

	if (argc != 4) {
		std::cout << "Usage is: ./atomic <min> <tau> <img_src> " << std::endl;
		return 1;
	}

	BeadFinder bf(std::stoi(argv[1]), std::stod(argv[2]), argv[3]);

	std::vector<Blob> v;
	bf.getBeads(v);

	for(unsigned int i = 0; i < v.size(); i++) {
		std::cout << v[i].mass() << " ";
		std::cout << v[i].toString() << std::endl;
	}
}

#endif

#ifdef BT

int main(int argc, char *argv[]) {

	if (argc < 5) {
		std::cout << "Usage is: ./atomic <min> <tau> <delta> <img_src> " << std::endl;
		return 1;
	}

	int min = std::stoi(argv[1]);
	double tau = std::stod(argv[2]);
	double delta = std::stod(argv[3]);
	int frameCount = argc - 4;

	std::vector<Blob> bef;
	std::vector<Blob> aft;

	BeadFinder bf(min, tau, argv[4]);
	bf.getBeads(bef);

	for(int k = 1; k < frameCount; k++) {

		double curDist, shortestDist;

		BeadFinder cur(min, tau, argv[4 + k]);
		cur.getBeads(aft);

		for(unsigned int i = 0; i < aft.size(); i++) {
			shortestDist = std::numeric_limits<double>::max();
			for(unsigned int j = 0; j < bef.size(); j++) {
				curDist = aft[i].distanceTo(bef[j]);
				if (curDist > delta)
					continue;
				if (curDist < shortestDist) {
					shortestDist = curDist;
				}
			}
			if (shortestDist != std::numeric_limits<double>::max())
				std::cout << std::left << std::setw(7) << std::setfill(' ') <<
				std::fixed << std::setprecision(4) << shortestDist << std::endl;
		}
		std::cout << std::endl;
		bef.clear();
		bef = aft;
		aft.clear();
	}
}

#endif
