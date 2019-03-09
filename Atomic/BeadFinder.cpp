/*
 * BeadFinder.cpp
 *
 *  Created on: Aug 5, 2018
 *      Author: rcyl
 */

#include <QImage>
#include <QColor>
#include <iostream>
#include "BeadFinder.h"

double luminance(QRgb rgb);

BeadFinder::BeadFinder(int min, double tau, char *src) : min(min), tau(tau), img(src){

	maxRow = img.height();
	maxCol = img.width();
	visited.resize(maxRow, std::vector<bool>(maxCol));

	/* to track which pixels have been visited via DFS */
	for(int r = 0; r < maxRow; r++) {
		for(int c = 0; c < maxCol; c++)
			visited[r][c] = false;
	}
}

void BeadFinder::getBeads(std::vector<Blob> &v) {

	for(int r = 0; r < maxRow; r++) {
		for(int c = 0; c < maxCol; c++) {
			Blob b;
			FindBlob(r, c, b);
			if (b.mass() != 0 && b.mass() >= min)
				v.push_back(b);
		}
	}
}

/* recursive function to add pixels into blob */
void BeadFinder::FindBlob(int row, int col, Blob &b) {

	if (row < 0 || row > maxRow -1) return;
	if (col < 0 || col > maxCol -1) return;

	if (visited[row][col]) return;

	visited[row][col] = true;

	double lum = luminance(img.pixel(col, row));

	if (lum < tau) return;

	b.add(col, row);
	FindBlob(row - 1, col, b);
	FindBlob(row, col + 1, b);
	FindBlob(row + 1, col, b);
	FindBlob(row, col -1, b);

}

/* see documentation of luminance.java */
inline double luminance(QRgb rgb) {
	QColor colour(rgb);
	return 0.299 * colour.red() + 0.587 * colour.green() + 0.114 * colour.blue();
}
