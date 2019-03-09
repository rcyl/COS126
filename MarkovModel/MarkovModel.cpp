/*
 * MarkovModel.cpp
 *
 *  Created on: Aug 2, 2018
 *      Author: rcyl
 */

#include <iostream>
#include <chrono>
#include <random>
#include "MarkovModel.h"


MarkovModel::MarkovModel(std::string text, int k) :
			k(k), str(text) {

	std::string substr;
	std::map<std::string, Tuple>::iterator it;
	char nextchar;

	/* create "circular text */
	str.append(text.begin(), text.begin() + k);

	for(unsigned int i = 0; i < text.length(); i++) {
		substr = str.substr(i, k);
		nextchar = str[i + k];
		it = map.find(substr);
		if (it == map.end()) {
			/* not found */
			/* create new array */
			std::array<int, 128> array{};
			array[nextchar]++;
			/* create new tuple */
			auto tuple = std::make_tuple(1, array);
			/* store inside map */
			map[substr] = tuple;
		} else {
			/* already exists */
			Tuple &tuple = map[substr];

			/* increase frequency by 1 */
			std::get<0>(tuple)++;

			/* get nextchar frequency array */
			std::get<1>(tuple)[nextchar]++;
		}
	}
}

MarkovModel::~MarkovModel() {}

int MarkovModel::order() { return k; }

std::string MarkovModel::toString() {

	std::string ret;

	for(const auto &pair : map) {
		ret.append(pair.first);

		auto tuple = pair.second;
		auto array = std::get<1>(tuple);
		for(int i = 0; i < 128; i++) {
			if (array[i] != 0) {
				ret.push_back(' ');
				ret.push_back(static_cast<char>(i));
				ret.push_back(' ');
				ret.append(std::to_string(array[i]));
			}
		}
		ret.append("\n");
	}

	return ret;
}

int MarkovModel::freq(const std::string kgram) {

	auto it = map.find(kgram);
	if (it == map.end())
		return 0;

	Tuple &tuple = map[kgram];

	return 	std::get<0>(tuple);
}

int MarkovModel::freq(const std::string kgram, char c) {

	auto it = map.find(kgram);
	if (it == map.end()) {
		std::cout << "kgram: " << kgram << std::endl;
		throw std::invalid_argument("kgram does not exist");
	}

	Tuple &tuple = map[kgram];

	return 	std::get<1>(tuple)[c];
}

char MarkovModel::random(const std::string kgram) {

	std::array<double, 128> prob {};
	int kgram_freq, char_freq;

	auto it = map.find(kgram);
	if (it == map.end()) {
		std::cout << "kgram: " << kgram << std::endl;
		throw std::invalid_argument("kgram does not exist");
	}

	kgram_freq = this->freq(kgram);

	/* build frequency table */
	for(int i = 0; i < 128; i++) {
		char_freq = freq(kgram, i);
		prob[i] = char_freq / static_cast<double>(kgram_freq);
	}

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine gen(seed);
	std::discrete_distribution<int>
				dist(prob.begin(), prob.end());

	return static_cast<char>(dist(gen));
}

