#include <iostream>
#include <fstream>
#include <array>
#include "MarkovModel.h"
#include "TextGenerator.h"
#include "FixCorrupted.h"

void testrand(const std::string text, const std::string kgram, int N = 100000);

#define FC

#ifdef TG

int main(int argc, char *argv[]) {

	if (argc != 4) {
		std::cout << "Usage is: markov <k> <T> < file.txt" << std::endl;
		return -1;
	}
	std::ifstream file(argv[3]);

	TextGenerator tg(atoi(argv[1]), atoi(argv[2]), file);

	return 0;
}
#endif


#ifdef FC

int main(int argc, char *argv[]) {

	if (argc != 4) {
		std::cout << argc << std::endl;
		std::cout << argv[1] << std::endl;
		std::cout << argv[2] << std::endl;
		std::cout << "Usage is: markov <k> <corrupt_text> < file.txt" << std::endl;
		return -1;
	}
	std::ifstream file(argv[3]);

	FixCorrupted fc(atoi(argv[1]), argv[2], file);

	return 0;
}
#endif


void testrand(const std::string text, const std::string kgram, int N) {

	MarkovModel model(text, kgram.length());
	std::array<int, 128> count {};

	for(int i = 0; i < N; i++) {
		char c = model.random(kgram);
		count[c]++;
	}

	std::cout << kgram << std::endl;
	for(int i = 0; i < 128; i++) {
		if (count[i] != 0) {
			std::cout << "char: " << char(i) << ", prob: " << count[i]/double(N) << std::endl;
		}
	}

}
