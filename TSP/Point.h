/*
 * Point.h
 *
 *  Created on: Aug 4, 2018
 *      Author: rcyl
 */

#ifndef POINT_H_
#define POINT_H_

#pragma once

#include <string>


class Point {

public:
	double x;
	double y;
	Point();
	Point(double x, double y);
	~Point();
	double distanceTo(Point &that);
	std::string toString();
};



#endif /* POINT_H_ */
