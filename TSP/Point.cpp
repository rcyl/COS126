/*
 * Point.cpp
 *
 *  Created on: Aug 4, 2018
 *      Author: rcyl
 */
#include "Point.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

Point::Point() : x(0), y(0) {}
Point::Point(double x, double y) : x(x), y(y) {}
Point::~Point() {}

double Point::distanceTo(Point &that) {
	double distsqr = pow((x - that.x), 2 ) + pow((y - that.y), 2);
	return sqrt(distsqr);
}

std::string Point::toString() {
	std::stringstream ss;
	ss << '(';
	ss << std::fixed << std::setprecision(4) << x;
	ss << ", ";
	ss << std::fixed << std::setprecision(4) << y;
	ss << ')';
	return ss.str();
}
