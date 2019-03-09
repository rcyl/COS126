/*
 * PointST.h
 *
 *  Created on: Aug 11, 2018
 *      Author: rcyl
 */

#ifndef POINTST_H_
#define POINTST_H_

#pragma once

#include "Point2D.h"
#include "RectHV.h"
#include <limits>
#include <map>
#include <vector>
#include <stdexcept>
#include <cstdio>

template <typename Value>
class PointST {
private:
	std::map<Point2D, Value> bst;
public:
	PointST() : bst() {}
	bool isEmpty() const { return bst.empty(); }
	int size() { return bst.size(); }

	void put(Point2D &p, Value val) {
		bst.insert(std::pair<Point2D, Value>(p, val));
	}

	Value get(Point2D &p) {

		if (this->isEmpty())
			throw std::underflow_error("bst is empty");

		auto it = bst.find(p);
		if (it == bst.end())
			throw new std::invalid_argument("point does not exist");

		return it->second;
	}

	bool contains(Point2D &p) {

		if (this->isEmpty())
			throw std::underflow_error("bst is empty");

		auto it = bst.find(p);
		return (it == bst.end() ? false : true);
	}

	std::vector<Point2D> points() {

		if (this->isEmpty())
			throw std::underflow_error("bst is empty");

		std::vector<Point2D> v;
		for(auto it : bst) v.push_back(it.first);
		return v;
	}

	std::vector<Point2D> range(const RectHV &rect) {

		if (this->isEmpty())
			throw std::underflow_error("bst is empty");

		std::vector<Point2D> v;
		for(auto it : bst) {
			if (rect.contains(it.first))
				v.push_back(it.first);
		}
		return v;
	}

	Point2D nearest(Point2D &p) {

		if (this->isEmpty())
			throw std::underflow_error("bst is empty");

		double max = std::numeric_limits<double>::max();
		Point2D *champ;
		double dist;

		for(auto it : bst) {
			Point2D cur = it.first;
			dist = cur.distanceSquaredTo(p);
			if (dist < max) {
				champ = &cur;
				max = dist;
			}
		}
		return *champ;
	}
};





#endif /* POINTST_H_ */
