/*
 * RectHV.h
 *
 *  Created on: Aug 11, 2018
 *      Author: rcyl
 */

#ifndef RECTHV_H_
#define RECTHV_H_

#pragma once

#include "Point2D.h"

class RectHV {
private:
	double xmin_, ymin_;
	double xmax_, ymax_;

public:
	RectHV(double xmin, double ymin, double xmax, double ymax);
	double xmin() const;
	double ymin() const;
	double xmax() const;
	double ymax() const;
	bool contains(const Point2D &that) const;
	bool intersects(RectHV &that) const;
	double distanceSquaredTo(Point2D &p);
	bool operator==(const RectHV &that) const;
	std::string toString() const;
};



#endif /* RECTHV_H_ */
