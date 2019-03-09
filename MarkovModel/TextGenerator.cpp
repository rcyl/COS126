/*
 * TextGenerator.cpp
 *
 *  Created on: Aug 3, 2018
 *      Author: rcyl
 */

#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include "TextGenerator.h"
#include "MarkovModel.h"

TextGenerator::TextGenerator(int k, int T, std::ifstream &fstream) :
				k(k), T(T) {

	std::string text((std::istreambuf_iterator<char>(fstream)),
					std::istreambuf_iterator<char>());

	MarkovModel model(text, k);
	std::deque<char> dq(text.begin(), text.begin() + k);

	std::string output(dq.begin(), dq.end());
	std::cout << output;

	for(int i = 0; i < T - k; i++) {
		std::string kgram(dq.begin(), dq.end());
		char c = model.random(kgram);
		std::cout << c;
		dq.push_back(c);
		dq.pop_front();
	}
	std::cout << std::endl;

	return;
}



