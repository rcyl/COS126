/*
 * main.cpp
 *
 *  Created on: 1 Aug, 2017
 *      Author: rcyl
 */
#include <QApplication>
#include <QDebug>
#include <iostream>
#include "nbody.h"

int main(int argc, char *argv[]) {

	QApplication app(argc, argv);

	QStringList args = QCoreApplication::arguments();

	if (args.size() < 3) {
		std::cout << "usage example is ./nbody 31557600 25000 < src/planets.txt " << std::endl;
		return -1;
	}

	QTextStream qtin(stdin);

	qreal T = args[1].toDouble();
	qreal dt = args[2].toDouble();

	NBody window(qtin, dt, T);

	window.setWindowTitle("Nbody");
	window.resize(1280, 960);
	window.show();

	return app.exec();
}


