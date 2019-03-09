/*
 * main.cpp
 *
 *  Created on: 3 Aug, 2017
 *      Author: rcyl
 */

#include <QApplication>
#include <iostream>
#include "sierpinski.h"

int main(int argc, char *argv[]) {

	QApplication app(argc, argv);

	QStringList args = QCoreApplication::arguments();

	if (args.size() < 3) {
		std::cout << "usage example is ./sierpinski N len" << std::endl;
		return -1;
	}

	int N = args[1].toInt();
	int len = args[2].toInt();

	Sierpinski window(N, len);

	window.setWindowTitle("Sierpinski");
	window.resize(1440, 900);
	window.show();

	return app.exec();
}


