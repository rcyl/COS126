/*
 * RectHV.cpp
 *
 *  Created on: Aug 11, 2018
 *      Author: rcyl
 */

#include "RectHV.h"
#include <sstream>
#include <iostream>

RectHV::RectHV(double xmin, double ymin, double xmax, double ymax)
		: xmin_(xmin), ymin_(ymin), xmax_(xmax), ymax_(ymax) {}

double RectHV::xmin() const { return xmin_; }
double RectHV::ymin() const { return ymin_; }
double RectHV::xmax() const { return xmax_; }
double RectHV::ymax() const { return ymax_; }

bool RectHV::contains(const Point2D &p) const{

	if (p.x() < this->xmin()) return false;
	if (p.x() > this->xmax()) return false;
	if (p.y() < this->ymin()) return false;
	if (p.y() > this->ymax()) return false;

	return true;
}

bool RectHV::intersects(RectHV &that) const{

	if (this->xmax() < that.xmin()) return false;
	if (this->ymax() < that.ymin()) return false;
	if (that.xmax() < this->xmin()) return false;
	if (that.ymax() < this->ymin()) return false;

	return true;
}

double RectHV::distanceSquaredTo(Point2D &p) {

	double dx = 0.0, dy = 0.0;
	if 		(p.x() < xmin_) dx = p.x() - xmin_;
	else if (p.x() > xmax_) dx = p.x() - xmax();
	if 		(p.y() < ymin_) dy = p.y() - ymin_;
	else if (p.y() > ymax_) dy = p.y() - ymax_;

	return dx * dx + dy * dy;
}

bool RectHV::operator==(const RectHV &that) const {

	if (this->xmin_ != that.xmin_) return false;
	if (this->xmax_ != that.xmax_) return false;
	if (this->ymin_ != that.ymin_) return false;
	if (this->ymax_ != that.ymax_) return false;

	return true;
}

std::string RectHV::toString() const {

	std::stringstream ss;
	ss << "[" << xmin_ << "," << xmax_ << "] X";
	ss << " [" << ymin_ << "," << ymax_ << "]";
	return ss.str();
}
