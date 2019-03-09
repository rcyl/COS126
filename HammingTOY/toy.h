/*
 * toy.h
 *
 *  Created on: 7 Aug, 2017
 *      Author: rcyl
 */

#pragma once

#include <stdint.h>
#include <iostream>
#include <fstream>

class Toy {

	public:
		Toy(std::ifstream & prog);
		void runProgram(std::istream & stdin, std::ostream & stdout);

	private:
		uint16_t pc;
		uint16_t reg[16];
		uint16_t mem[256];
		std::ifstream & prog;
};

