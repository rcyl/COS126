/*
 * fcircle.cpp
 *
 *  Created on: 5 Aug, 2017
 *      Author: rcyl
 */

#include "fcircle.h"

FCircle::FCircle(qreal cx, qreal cy, qreal radius) : cx(cx), cy(cy), radius(radius) { }

qreal FCircle::getCx(){ return cx; }

qreal FCircle::getCy(){ return cy; }

qreal FCircle::getRadius(){ return radius; }
