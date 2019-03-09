/*
 * main.cpp
 *
 *  Created on: Aug 4, 2018
 *      Author: rcyl
 */

#include <QApplication>
#include <QDebug>
#include <iostream>
#include <iomanip>
#include "Point.h"
#include "Tour.h"

void debug();

int main(int argc, char *argv[]) {

	QApplication app(argc, argv);

	std::string line;
	int width, height;
	double x, y;

	std::cin >> width;
	std::cin >> height;

	Tour tour(width, height);

	while((std::cin >> x) && (std::cin >> y) ) {
		Point p(x, y);
		tour.insertNearest(p);
//		tour.insertSmallest(p);
	}

	std::cout << tour.toString() << std::endl;
	std::cout << "len: " << std::fixed <<
			std::setprecision(4) << tour.length() << std::endl;

	tour.draw();
	app.exec();
}

void debug() {

	Point a(100, 100);
	Point b(500, 100);
	Point c(500, 500);
	Point d(100, 500);

	Tour tour4(a, b, c, d);
	std::cout << tour4.toString() << std::endl;
	std::cout << tour4.length() << std::endl;
	tour4.draw();
}

