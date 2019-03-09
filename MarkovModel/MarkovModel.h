/*
 * MarkovModel.h
 *
 *  Created on: Aug 2, 2018
 *      Author: rcyl
 */

#ifndef MARKOVMODEL_H_
#define MARKOVMODEL_H_

#include <vector>
#include <map>
#include <tuple>
#include <array>

/* tuple stores the frequency of a certain kgram,
 * and the array stores the frequency of the char
 * following the kgram
 */
typedef std::tuple<int, std::array<int, 128>> Tuple;

class MarkovModel {
private:
	int k;
	std::string str; /* input appended with k chars at start */
	std::map<std::string, Tuple> map;

public:
	MarkovModel(std::string text, int k);
	~MarkovModel();
	int order();
	std::string toString();
	int freq(const std::string kgram);
	int freq(const std::string kgram, char c);
	char random(const std::string kgram);
};


#endif /* MARKOVMODEL_H_ */
