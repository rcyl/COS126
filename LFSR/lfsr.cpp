/*
 * lfsr.cpp
 *
 *  Created on: Jul 29, 2018
 *      Author: rcyl
 */


#include <iostream>
#include <stdexcept>
#include "lfsr.h"

LFSR::LFSR(std::string seed, int tap) {

	len = seed.length();

	if (tap >= len) {
		throw std::invalid_argument
		("tap position can't be higher than len");
	}

	tapidx = len - tap;

	for(int i = 0; i < len; i++) {
		cur.push_back((int)(seed.at(i) - '0'));
	}

}

LFSR::~LFSR() {}

int LFSR::length() { return len; }

inline int LFSR::bitAt(int i) {

	return cur[i];
}

std::string LFSR::toString() {

	std::string str;
	for(std::deque<int>::iterator it = cur.begin(); it != cur.end(); ++it) {
		str.append(std::to_string(*it));
	}

	return str;
}

int LFSR::step() {

	int msb =  cur.front();
	int res = msb ^ cur[tapidx];

	cur.pop_front();
	cur.push_back(res);

	return res;
}

int LFSR::generate(int k) {

	if (k < 0)
		throw std::invalid_argument("i can't be negative");

	int step, res = 0;

	for(int i = 0; i < k; i++) {
		step = this->step();
		res = res * 2 + step;
	}

	return res;
}



