/*
 * lfsr.h
 *
 *  Created on: Jul 29, 2018
 *      Author: rcyl
 */

#ifndef LFSR_H_
#define LFSR_H_

#include <string>
#include <deque>

#pragma once

class LFSR {
private:
	std::deque<int> cur;
	int tapidx;
	int len;

public:
	LFSR(std::string seed, int tap);
	~LFSR();
	int length();
	int bitAt(int i);
	std::string toString();
	int step();
	int generate(int k);
};



#endif /* LFSR_H_ */
