/*
 * Blob.h
 *
 *  Created on: Aug 5, 2018
 *      Author: rcyl
 */

#ifndef BLOB_H_
#define BLOB_H_

#pragma once

#include <string>
#include <vector>

class Blob {
private:
	int xsum;
	int ysum;
	int count;
	double xave;
	double yave;
public:
	Blob();
	~Blob();
	void add(int x, int y);
	int mass();
	double distanceTo(Blob &that);
	std::string toString();
};




#endif /* BLOB_H_ */
