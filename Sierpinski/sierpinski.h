/*
 * sierpinski.h
 *
 *  Created on: 3 Aug, 2017
 *      Author: rcyl
 */

#pragma once

#include <QWidget>
#include <QPainter>
#include <QTextStream>
#include <vector>
#include "fcircle.h"

class Sierpinski : public QWidget {

	public:
		Sierpinski(int N, qreal len, QWidget *parent = 0);
		~Sierpinski();

	protected:
		void paintEvent(QPaintEvent *);

	private:
		void drawTri();
		void drawCircle();
		QPair<qreal, qreal> getRotated(qreal radius, qreal angle, qreal cx, qreal cy);
		void getSmallCircle(qreal sradius, qreal x, qreal y, qreal angle);
		qreal calcTriHeight(qreal);
		void triangle(int n , qreal x, qreal y, qreal len);
		void circle(int n , qreal x, qreal y, qreal radius);

	private:
		QVector<QPolygon> triangles;
		std::vector<FCircle> fcircles;
		qreal len;
};
