/*
 * body.cpp
 *
 *  Created on: 31 Jul, 2017
 *      Author: rcyl
 */

#include <QtMath>
#include <iostream>
#include "body.h"

const qreal G = 6.67e-11;

Body::Body(qreal px, qreal py, qreal vx, qreal vy,
		qreal mass, qreal dt, QString fileName) :
		px(px), py(py), vx(vx), vy(vy), mass(mass),
		dt(dt), fileName(fileName)
{
	this->ax = 0;
	this->ay = 0;
	this->fileName = fileName;
	this->image.load("src/" + fileName);
}

Body::Body() {}

/* returns force that other body is acting on this body */
QPair<qreal, qreal> Body::getForce(Body & that) {

	QPair<qreal, qreal> force;

	qreal dx = that.getPx() - this->px;
	qreal dy = that.getPy() - this->py;

	qreal radius = qSqrt(qPow(dx, 2) + qPow(dy,2));

	qreal fr = (G * this->mass * that.getMass()) / qPow(radius, 2);

	force.first = fr * dx / radius;
	force.second = fr * dy / radius;

	return force;
}


void Body::updateAcc(QPair<qreal, qreal> fsum) {

	this->ax = fsum.first / this->mass;
	this->ay = fsum.second / this->mass;
}

void Body::updateVel() {

	this->vx += this->ax * dt;
	this->vy += this->ay * dt;
}

void Body::updatePos() {

	this->px += this->vx * dt;
	this->py += this->vy * dt;
}


qreal Body::getPx() { return this->px; }
qreal Body::getPy() { return this->py; }
qreal Body::getVx() { return this->vx; }
qreal Body::getVy() { return this->vy; }
qreal Body::getMass() { return this->mass; }
QString Body::getFileName() { return this->fileName; }
QImage Body::getImage() { return this->image; }
