/*
 * main.cpp
 *
 *  Created on: Aug 11, 2018
 *      Author: rcyl
 */


#include <iostream>
#include "Point2D.h"
#include "RectHV.h"
#include "PointST.h"

void debugPoint2D();
void debugRecvHV();
void DebugPointST();

int main() {


	return 0;
}

void DebugPointST() {

	PointST<int> pst;
	Point2D p1(1,1);
	Point2D p2(2,2);
	Point2D p3(3,3);

	std::cout << pst.get(p1) << std::endl;
	std::cout << (pst.contains(p1) ? "yes" : "no") << std::endl;

	std::vector<Point2D> v = pst.points();
	for(Point2D p : v)
		std::cout << p.toString() << std::endl;

	RectHV rect(0, 0, 5, 5);
	std::vector<Point2D> range = pst.range(rect);
	for(Point2D p : range)
		std::cout << "range-> " << p.toString() << std::endl;

	Point2D p8(9,10);
	Point2D near = pst.nearest(p8);
	std::cout << "nearest->" << near.toString() << std::endl;
}

void debugRecvHV() {

	RectHV r1(0,1,2,3);
	std::cout << r1.toString() << std::endl;
}

void debugPoint2D() {

	Point2D p1(1, 1);
	Point2D p2(3, 5);
	Point2D p3(2, 2);

	std::cout << p1.toString() << std::endl;
	std::cout << p2.toString() << std::endl;
	std::cout << p1.distanceSquaredTo(p2) << std::endl;
	std::cout << ((p2 < p3) ? "less than" : "not less than")
				<< std::endl;

	std::cout << ((p3 == p2) ? "equal" : "not equal")
				<< std::endl;

}
