/*
 * nbody.cpp
 *
 *  Created on: 31 Jul, 2017
 *      Author: rcyl
 */
#include <QDebug>
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include "nbody.h"

NBody::NBody(QTextStream & qtin, qreal dt, qreal T, QWidget *parent) :
	QWidget(parent), dt(dt), T(T)
{
	QStringList list;

	setStyleSheet("background-color:black;");

	while(!qtin.atEnd()) {
		QString line = qtin.readLine();
		if (!line.isEmpty())
			list.append(line);
	}

	this->N = list.first().toInt();
	this->radius = list[1].toDouble();

	for(int i = 2; i < N + 2; i++) {
		QStringList tokens = list[i].split(QRegExp("\\s+"), QString::SkipEmptyParts);
		qreal px = tokens[0].toDouble();
		qreal py = tokens[1].toDouble();
		qreal vx = tokens[2].toDouble();
		qreal vy = tokens[3].toDouble();
		qreal mass = tokens[4].toDouble();
		QString fileName = tokens[5];
		Body body(px, py, vx, vy, mass, dt, fileName);
		bodies.append(body);
	}

	this->wratio = WIDTH / (2 * this->radius);
	this->hratio = HEIGHT / (2 * this->radius);
	this->elapsedTime = 0;

	timerId = startTimer(DELAY);
}

void NBody::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);
    doDrawing();
}

void NBody::doDrawing() {

	QPainter qp(this);
	qp.translate( width() / 2, height() / 2);
	qp.scale(1, -1); /* reverse y axis orientation to point upwards */

	/* reverse direction on y as per drawing conventions */
	for(int i = 0; i < bodies.size(); i++) {
		qreal x = bodies[i].getPx() * wratio;
		qreal y = (bodies[i].getPy() * hratio);
		qp.drawImage(x, y, bodies[i].getImage());
	}
}

void NBody::timerEvent(QTimerEvent *) {

	if (elapsedTime < this->T) {
		for(int i = 0; i < bodies.length(); i++) {
			bodies[i].updateAcc(calcForce(bodies[i], i));
			bodies[i].updateVel();
			bodies[i].updatePos();
		}
		elapsedTime += dt;
	} else {
		printEndState();
		killTimer(timerId);
	}
	repaint();
}

/* calculate forces on single body fom other bodies and returns QPair of force*/
QPair<qreal, qreal> NBody::calcForce(Body & body, int idx) {

	QPair<qreal, qreal> fsum; /* sum of all forces from other bodies*/
	QPair<qreal, qreal> force;
	for(int j = 0; j < bodies.size(); j++) {
		force = {};
		if (j == idx) /* can't act on yourself */
			continue;
		force = body.getForce(bodies[j]);
		fsum.first += force.first;
		fsum.second += force.second;
	}
	return fsum;
}

void NBody::printEndState() {

	std::cout << this->N << std::endl;
	std::cout << this->radius << std::endl;
	std::cout.precision(4);

	for(int i = 0; i < bodies.size(); i++) {
		std::cout << std::setw(10) << std::scientific << bodies[i].getPx() << " ";
		std::cout << std::setw(10) << std::scientific << bodies[i].getPy() << " ";
		std::cout << std::setw(10) << std::scientific << bodies[i].getVx() << " ";
		std::cout << std::setw(10) << std::scientific << bodies[i].getVy() << " ";
		std::cout << std::setw(10) << std::scientific << bodies[i].getMass() << " ";
		std::cout << std::setw(10) << bodies[i].getFileName().toStdString() << std::endl;
	}
}

NBody::~NBody() { };

