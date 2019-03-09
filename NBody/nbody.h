/*
 * nbody.h
 *
 *  Created on: 31 Jul, 2017
 *      Author: rcyl
 */
#pragma once

#include <QWidget>
#include <QPainter>
#include <QTextStream>
#include "body.h"

class NBody : public QWidget{

	public:
		NBody(QTextStream & qin, qreal dt, qreal T, QWidget *parent = 0);
		~NBody();

	protected:
		void paintEvent(QPaintEvent *);
		void timerEvent(QTimerEvent *);

	private:
		int timerId;
		qreal dt;
		qreal T;
		int N; /* number of bodies */
		qreal radius;
		qreal elapsedTime;
		qreal wratio;
		qreal hratio;
		QVector<Body> bodies;
		QPair<qreal, qreal> calcForce(Body &, int);
		void doDrawing();
		void printEndState();
		const int WIDTH = 1280;
		const int HEIGHT = 960;
		const int DELAY = 50;

};
