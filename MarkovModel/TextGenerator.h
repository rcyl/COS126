/*
 * TextGenerator.h
 *
 *  Created on: Aug 3, 2018
 *      Author: rcyl
 */

#ifndef TEXTGENERATOR_H_
#define TEXTGENERATOR_H_


class TextGenerator {
private:
	int k;
	int T;
public:
	TextGenerator(int k, int T, std::ifstream &fstream);
};


#endif /* TEXTGENERATOR_H_ */
