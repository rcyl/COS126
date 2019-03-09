/*
 * FixCorrupted.cpp
 *
 *  Created on: Aug 3, 2018
 *      Author: rcyl
 */
#include "MarkovModel.h"
#include "FixCorrupted.h"
#include <fstream>
#include <deque>
#include <array>

char MostFreq(MarkovModel &model, std::string kgram, int N);

FixCorrupted::FixCorrupted(int k, std::string input, std::ifstream &fstream)
			:k(k) {

	std::string text((std::istreambuf_iterator<char>(fstream)),
						std::istreambuf_iterator<char>());

	MarkovModel model(text, k);
	std::deque<char> dq(input.begin(), input.begin() + k);

	for(unsigned int i = k; i < input.length(); i++) {
		std::string kgram(dq.begin(), dq.end());
		if (input[i] == '~') {
			input[i] = MostFreq(model,kgram, 1000);
			dq.clear();
		} else {
			dq.push_back(input[i]);
			if (dq.size() > static_cast<unsigned int>(k))
				dq.pop_front();
		}
	}
	std::cout << input << std::endl;
}

char MostFreq(MarkovModel &model, std::string kgram, int N) {

	std::array<int, 128> arr {};
	char c;
	int max = -1;
	int idx;

	/* get count of each char */
	for(int i = 0; i < N; i++) {
		c = model.random(kgram);
		arr[c]++;
	}

	for(int i = 0; i < 128; i++) {
		if (arr[i] > max) {
			idx = i;
			max = arr[i];
		}
	}

	return static_cast<char>(idx);
}

