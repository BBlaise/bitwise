//============================================================================
// Name        : new_cpp_project.cpp
// Author      : Bryan Blaise
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdint.h>
#include <math.h>
#include <bitset>

#include "bitwise.h"

using namespace std;

int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	/*
	uint8_t tx_msg = 0b10011011;
	uint8_t bits_to_clear[2] = {1, 0};
	//clearBit(tx_msg, 0);
	//clearBit(tx_msg, 1);
	clearBits(tx_msg, bits_to_clear, 2);

	bitset<8> tx_msg_b(tx_msg);
	cout << tx_msg_b << endl;

	uint8_t mask;
	//mask = 0b00;
	//mask = 0b01;
	mask = 0b10;
	setMask(tx_msg, mask, 1, 0);

	bitset<8> final(tx_msg);
	cout << tx_msg_b << endl;
	*/

	uint8_t byte = 0b11111111;
	bitset<8> byte_b(byte);
	cout << byte_b << endl;
	uint8_t to_clear = 0b01101100;
	clearBits(byte, to_clear);
	bitset<8> result(byte);
	cout << result << endl;

	return 0;
}


