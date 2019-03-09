/*
 * body.h
 *
 *  Created on: 31 Jul, 2017
 *      Author: rcyl
 */
#pragma once

#include <QWidget>
#include <QPair>

class Body {

	public:
		Body(qreal px, qreal py, qreal vx, qreal vy, qreal mass,
				qreal dt, QString fileName);
		Body();
		QPair<qreal, qreal> getForce(Body &);
		void updateAcc(QPair<qreal, qreal>);
		void updateVel();
		void updatePos();
		qreal getPx();
		qreal getPy();
		qreal getVx();
		qreal getVy();
		qreal getMass();
		QString getFileName();
		QImage getImage();

	private:
		qreal px;
		qreal py;
		qreal vx;
		qreal vy;
		qreal ax; /* acceleration of 1 step ago */
		qreal ay;
		qreal mass;
		qreal dt;
		QString fileName;
		QImage image;
};
