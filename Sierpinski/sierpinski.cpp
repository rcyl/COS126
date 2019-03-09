/*
 * sierpinski.cpp
 *
 *  Created on: 3 Aug, 2017
 *      Author: rcyl
 */

#include <QtMath>
#include <iostream>
#include "sierpinski.h"

const qreal SQRT3 = 1.73205080757;

Sierpinski::Sierpinski(int N, qreal len, QWidget *parent) :
		QWidget(parent), len(len) {

	//triangle(N, 0, 0, len);
	circle(N, 0, 0, len);
	repaint();
};

Sierpinski::~Sierpinski() { };

/* returns a point x,y after a point of "radius" len from cx,cy has been rotated
 * CW by theta at cx, and cy */

QPair<qreal, qreal> Sierpinski::getRotated(qreal radius, qreal angle, qreal cx, qreal cy) {

	QPair<qreal, qreal> point;
	qreal angleRad = qDegreesToRadians(angle);

	point.first = cx + radius * qSin(angleRad);
	point.second = cy + radius * qCos(angleRad);

	return point;
}

qreal Sierpinski::calcTriHeight(qreal len) { return len / 2 * SQRT3; }

void Sierpinski::triangle(int n, qreal x, qreal y, qreal length) {

	if (n == 0)
		return;

	QPolygon poly;
	qreal height = calcTriHeight(length);

	poly << QPoint(x, y) << QPoint(x - length/2, (y + height)) <<  QPoint(x + length/2, (y + height));
	triangles.append(poly);

	triangle(n - 1, x - length/2, y, length / 2); /* left side */
	triangle(n - 1, x, (y + height), length / 2); /* top side */
	triangle(n - 1, x + length/2, y, length / 2); /* right side */
}

void Sierpinski::circle(int n, qreal x, qreal y, qreal radius) {

	if (n == 0)
		return;

	fcircles.push_back(FCircle(x, y, radius));
	QPair<qreal, qreal> point;
	/* populate main circles */
	for(qreal angle = 0; angle < 360; angle += 60) {
		point = getRotated(2 * radius, angle, x, y);
		fcircles.push_back(FCircle(point.first, point.second, radius));
	}
	/* populate small circles */
	getSmallCircle(radius, x, y, 30);
	getSmallCircle(radius, x, y, 150);
	getSmallCircle(radius, x, y, 210);
	getSmallCircle(radius, x, y, 330);


	/* recursive loop */
	circle(n - 1, x, y, radius/3);
	for(qreal angle = 0; angle < 360; angle += 60) {
		point = getRotated(2 * radius, angle, x, y);
		circle(n - 1, point.first, point.second, radius/3);
	}
}

void Sierpinski::getSmallCircle(qreal radius, qreal x, qreal y, qreal angle){

	qreal ctr_radius = 2 / SQRT3 * radius;
	qreal sradius = ctr_radius - radius;
	QPair<qreal, qreal> point;
	point = getRotated(ctr_radius, angle , x, y);
	fcircles.push_back(FCircle(point.first, point.second, sradius));
}

void Sierpinski::paintEvent(QPaintEvent *e) {

	 Q_UNUSED(e);
	 //drawTri();
	 drawCircle();
}

void Sierpinski::drawCircle() {

	QPainter qp(this);
	qp.translate(width()/2 , height()/2);
	qp.scale(1, -1); /* reverse y axis orienatation to point upwards */
	qp.setRenderHints(QPainter::Antialiasing);

	QPen pen(Qt::black, 1, Qt::SolidLine);
	qp.setPen(pen);
	QBrush brush;

	for(uint i = 0; i < fcircles.size(); i++) {
		QPointF center(fcircles[i].getCx(), fcircles[i].getCy());
		qp.drawEllipse(center, fcircles[i].getRadius(), fcircles[i].getRadius());
	}
	/* paint outline */
	qp.drawEllipse(QPointF(0, 0), 3 * len, 3 * len);
}

void Sierpinski::drawTri() {

	QPainter qp(this);
	qp.translate(width()/2 , height()/2);
	qp.scale(1, -1); /* reverse y axis orientation to point upwards */
	qp.setRenderHints(QPainter::Antialiasing);

	QPen pen(Qt::black, 1, Qt::SolidLine);
	qp.setPen(pen);
	QBrush brush;
	brush.setColor(Qt::red);
	brush.setStyle(Qt::SolidPattern);
	QPainterPath path;

	for(int i = 0; i < triangles.size(); i++) {
		path = {};
		path.addPolygon(triangles[i]);
		qp.drawPolygon(triangles[i]);
		qp.fillPath(path, brush);
	}
	/* paint outline */
	QPolygon outline;
	qreal h = calcTriHeight(len);
	outline << QPoint(-len, 0) << QPoint(0, h * 2) <<  QPoint(len, 0);
	qp.drawPolygon(outline);

}
