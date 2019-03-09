/*
 * Point2D.h
 *
 *  Created on: Aug 11, 2018
 *      Author: rcyl
 */

#ifndef POINT2D_H_
#define POINT2D_H_

#pragma once

#include <string>

class Point2D {
private:
	double x_;
	double y_;
public:
	Point2D(double x, double y);
	double x() const;
	double y() const;
	double distanceSquaredTo(Point2D &that);
	bool operator<(const Point2D &that) const;
	bool operator==(const Point2D &that) const;
	std::string toString() const;
};



#endif /* POINT2D_H_ */
