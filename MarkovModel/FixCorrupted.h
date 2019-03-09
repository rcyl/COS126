/*
 * FixCorrupted.h
 *
 *  Created on: Aug 3, 2018
 *      Author: rcyl
 */

#ifndef FIXCORRUPTED_H_
#define FIXCORRUPTED_H_

#include <iostream>
#include <string>

class FixCorrupted {
private:
	int k;
public:
	FixCorrupted(int k, std::string input, std::ifstream &fstream);
};


#endif /* FIXCORRUPTED_H_ */
