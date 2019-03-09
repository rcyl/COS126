/*
 * Blob.cpp
 *
 *  Created on: Aug 5, 2018
 *      Author: rcyl
 */

#include "Blob.h"
#include <cmath>
#include <sstream>
#include <iomanip>

Blob::Blob() : xsum(0), ysum(0), count(0), xave(0), yave(0) { }

Blob::~Blob() {};

void Blob::add(int x, int y) {

	xsum += x;
	ysum += y;
	count++;

	xave = xsum / static_cast<double>(count);
	yave = ysum / static_cast<double>(count);
}

int Blob::mass() { return count; }

double Blob::distanceTo(Blob &that) {

	return sqrt(pow((that.xave - xave), 2) + pow((that.yave - yave), 2));
}

std::string Blob::toString() {

	std::stringstream ss;
	ss << '(';
	ss << std::fixed << std::setprecision(4) << xave;
	ss << ", ";
	ss << std::fixed << std::setprecision(4) << yave;
	ss << ')';

	return ss.str();
}


