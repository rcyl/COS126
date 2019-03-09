/*
 * fcircle.h
 * fractal circles
 *
 *  Created on: 5 Aug, 2017
 *      Author: rcyl
 */

#pragma once

#include <QtGlobal>

class FCircle {

	public:
		FCircle(qreal cx, qreal cy, qreal radius);
		qreal getCx();
		qreal getCy();
		qreal getRadius();
	private:
		qreal cx;
		qreal cy;
		qreal radius;
};
