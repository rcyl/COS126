/*
 * BeadFinder.h
 *
 *  Created on: Aug 5, 2018
 *      Author: rcyl
 */

#ifndef BEADFINDER_H_
#define BEADFINDER_H_

#pragma once

#include <QImage>
#include <vector>
#include "Blob.h"

class BeadFinder {
private:
	int min;
	double tau;
	QImage img;
	int maxRow;
	int maxCol;
	std::vector<std::vector<bool>> visited;
	void FindBlob(int row, int col, Blob &b);
public:
	BeadFinder(int min, double tau, char* src);
	void getBeads(std::vector<Blob> &v);
};

#endif /* BEADFINDER_H_ */
