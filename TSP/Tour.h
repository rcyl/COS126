/*
 * Tour.h
 *
 *  Created on: Aug 4, 2018
 *      Author: rcyl
 */

#ifndef TOUR_H_
#define TOUR_H_

#pragma once

#include <QWidget>
#include <QPainter>
#include "Point.h"

class Tour : public QWidget {

	Q_OBJECT

private:
	struct Node {
		Point p;
		Node *next;
	};
	Node *start;
	Node *bnode;
	Node *cnode;
	Node *dnode;
	int sz;
	int width;
	int height;

protected:
	void paintEvent(QPaintEvent *);

public:
	Tour(int width, int height);
	Tour(Point &a, Point &b,
			Point &c, Point &d, int width = 1440, int height = 900);
	~Tour();
	int size();
	double length();
	std::string toString();
	void draw();
	void insertNearest(Point &p);
	void insertSmallest(Point &p);
};



#endif /* TOUR_H_ */
