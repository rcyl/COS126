/*
 * Tour.cpp
 *
 *  Created on: Aug 4, 2018
 *      Author: rcyl
 */

#include <iostream>
#include <sstream>
#include <limits>
#include "Tour.h"

Tour::Tour(int width, int height) : start(nullptr), bnode(nullptr),
				cnode(nullptr), dnode(nullptr),
				sz(0), width(width), height(height){

}

Tour::Tour(Point &a, Point &b, Point &c, Point &d, int width, int height)
			: width(width), height(height) {

	sz = 4;
	start = new Node;
	bnode = new Node;
	cnode = new Node;
	dnode = new Node;

	start->p = a;
	start->next = bnode;

	bnode->p = b;
	bnode->next = cnode;

	cnode->p = c;
	cnode->next = dnode;

	dnode->p = d;
	dnode->next = start;
}

int Tour::size() { return sz; }

double Tour::length() {

	if (start == nullptr)
		return 0;

	double length = 0;
	Node *prev = start;

	for(Node *node = start->next; node != start; node = node->next) {
		length += node->p.distanceTo(prev->p);
		prev = node;
	}
	length += prev->p.distanceTo(start->p);

	return length;
}

std::string Tour::toString() {

	if (start == nullptr)
		return "";

	std::stringstream ss;
	Node *node = start;
	ss << start->p.toString();

	for(node = node->next; node != start; node = node->next){
		ss << std::endl << node->p.toString();
	}
	return ss.str();
}

Tour::~Tour() {

	//std::cout << "In tour destuctor " << std::endl;

	if (start == nullptr)
		return;

	for(Node *node = start->next; node != start; node = node->next) {
		delete node;
	}

	delete start;
}

void Tour::insertNearest(Point &p) {

	Node *insert = new Node;
	insert->p = p;

	if (start == nullptr) {
		start = insert;
		start->next = start;
		return;
	}

	double nearestDist = std::numeric_limits<double>::max();
	double dist;
	Node *node = start;
	Node *nearest = start;

	do {
		dist = node->p.distanceTo(p);
		if (dist < nearestDist) {
			nearestDist = dist;
			nearest = node;
		}
		node = node->next;
	} while(node != start);

	/* insert nearest */
	insert->next = nearest->next;
	nearest->next = insert;
}

void Tour::insertSmallest(Point &p) {

	Node *insert = new Node;
	insert->p = p;

	if (start == nullptr) {
		start = insert;
		start->next = start;
		return;
	}

	double smallestlen = std::numeric_limits<double>::max();
	double tourlen;
	Node *node = start;
	Node *smallest = start;

	do {
		Node *next = node->next;
		tourlen = p.distanceTo(node->p) + next->p.distanceTo(p)
					- next->p.distanceTo(node->p);
		if (tourlen < smallestlen) {
			smallestlen = tourlen;
			smallest = node;
		}
		node = node->next;
	} while(node != start);

	/* insert smallest */
	insert->next = smallest->next;
	smallest->next = insert;
}

void Tour::draw() { this->show(); }

void Tour::paintEvent(QPaintEvent *e) {

	 Q_UNUSED(e);
	 this->resize(width, height);
	 QPainter qp(this);
	 qp.translate(0, height);
	 qp.scale(1, -1);
	 qp.setPen(QPen(Qt::black, 1, Qt::SolidLine));

	 Node *prev = start;
	 for(Node *node = start->next; node != start; node = node->next){
		 qp.drawLine(prev->p.x, prev->p.y, node->p.x, node->p.y);
		 prev = node;
	 }
	 qp.drawLine(prev->p.x, prev->p.y, start->p.x, start->p.y);
}
