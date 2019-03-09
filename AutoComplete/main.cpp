/*
 * main.cpp
 *
 *  Created on: Aug 12, 2018
 *      Author: rcyl
 */


#include "Autocomplete.h"
#include "Term.h"
#include "BSDeluxe.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>

std::vector<std::string> split(const std::string &line) {

	std::vector<std::string> v;
	std::string buf;
	std::stringstream ss(line);
	while(ss >> std:: skipws >> buf) {
		v.push_back(buf);
	}
	return v;
}

std::string merge(std::vector<std::string> &v) {

	std::stringstream ss;
	for(unsigned int i = 1; i < v.size(); i++) {
		ss << v[i];
		if (i != v.size() - 1) ss << " ";
	}
	return ss.str();
}
void debug();

int main(int argc, char *argv[]) {

	//debug();
	if (argc < 3) {
		std::cout << "Usage is auto <file> <k>" << std::endl;
		return -1;
	}

	int n;
	std::string token, query;
	std::string line;
	//long weight;

	std::vector<Term> terms;
	std::ifstream src(argv[1]);
	src >> n;
	std::getline(src, line);

	for(int i = 0; i < n; i++) {
		std::getline(src, line);
		std::vector<std::string> tokens = split(line);
		terms.push_back(Term(merge(tokens), std::stol(tokens[0])));
	}

	Autocomplete autocomplete(terms);
	std::string prefix;
	int matches;
	int k = std::stoi(argv[2]);

	while(std::getline(std::cin, prefix)) {
		std::vector<Term> results = autocomplete.allMatches(prefix);
		matches = autocomplete.numberOfMatches(prefix);
		std::cout << matches << " matches" << std::endl;
		for(int i = 0; i < std::min(k, static_cast<int>(results.size())); i++)
			std::cout << results[i].toString() << std::endl;
	}
	return 0;
}


void debug() {

	std::vector<Term> v;
	v.push_back(Term("automobile", 1));
	v.push_back(Term("automatic", 2));
	v.push_back(Term("automobile", 3));
	v.push_back(Term("automatic", 4));
	v.push_back(Term("automobile", 5));
	v.push_back(Term("automatic", 6));
	v.push_back(Term("automobile", 7));
	v.push_back(Term("automatic", 8));
	v.push_back(Term("automobile", 9));
	v.push_back(Term("automatic", 10));
	v.push_back(Term("automobile", 11));
	v.push_back(Term("automatic", 12));

	sort(v.begin(), v.end());
	std::cout << "lexi sort sort" << std::endl;
	for(Term t : v) std::cout << t.toString() << std::endl;

	std::string prefix("a");
	Term t(prefix, 1);

	int first = BSDeluxe<Term>::firstIndexOf(v, t, ByPrefixOrder<Term>(prefix.length()));
	std::cout << "first-> " << first << std::endl;

	int last = BSDeluxe<Term>::lastIndexOf(v, t, ByPrefixOrder<Term>(prefix.length()));
	std::cout << "last->: " << last << std::endl;

	sort(v.begin() + first, v.begin() + last + 1, ReverseWeightOrder<Term>());
	std::cout << "after sorting, reverse weight" << std::endl;
	for(Term t : v) std::cout << t.toString() << std::endl;
}
