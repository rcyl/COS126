/*
 * Autocomplete.h
 *
 *  Created on: Aug 12, 2018
 *      Author: rcyl
 */

#ifndef AUTOCOMPLETE_H_
#define AUTOCOMPLETE_H_

#pragma once
#include "Term.h"
#include <vector>

class Autocomplete {

private:
	std::vector<Term> terms;

public:
	Autocomplete(std::vector<Term> &terms);
	std::vector<Term> allMatches(const std::string &prefix);
	int numberOfMatches(const std::string &prefix);

};

#endif /* AUTOCOMPLETE_H_ */
