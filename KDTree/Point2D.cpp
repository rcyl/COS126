/*
 * Point2D.cpp
 *
 *  Created on: Aug 11, 2018
 *      Author: rcyl
 */

#include "Point2D.h"
#include <sstream>
#include <cmath>

Point2D::Point2D(double x, double y): x_(x), y_(y) {}
double Point2D::x() const { return x_; }
double Point2D::y() const { return y_; }

double Point2D::distanceSquaredTo(Point2D &that) {

	return pow((that.y() - this->y()), 2)
			+ pow((that.x() - this->x()), 2);
}

bool Point2D::operator<(const Point2D &that) const{

	if (this->y() < that.y()) return true;

	if (this->y() == that.y() && this->x() < that.x()) return true;

	return false;
}

bool Point2D::operator==(const Point2D &that) const {

	if (this->x() == that.x() && this->y() == that.y()) return true;

	return false;
}

std::string Point2D::toString() const {

	std::stringstream ss;
	ss << "(" << x_<< "," << y_ << ")";
	return ss.str();
}
