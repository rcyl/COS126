/*
 * play.cpp
 *
 *  Created on: Aug 2, 2018
 *      Author: rcyl
 */

#include <iostream>
#include <array>
#include <random>
#include <vector>
#include <chrono>

int main() {

	std::array<int, 128> arr {};
	std::array<double, 128> weight {};
	std::string str;

	weight['a'] = 0.4;
	weight['b'] = 0.6;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine gen(seed);
	std::discrete_distribution<int>
		dist(weight.begin(), weight.end());

	for(int i = 0; i < 10; i++) {
		int r = dist(gen);
		std::cout << static_cast<char>(r) << std::endl;
	}

	return 0;
}

