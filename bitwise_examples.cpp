//============================================================================
// Name        : new_cpp_project.cpp
// Author      : Bryan Blaise
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <bitset>

#include "bitwise.h"

using namespace std;

int main(){
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	uint8_t original = 0b00011001;
	bitset<8> o(original);
	cout << o << endl;
	uint8_t final = 0;

/*
	// Set a bit
	final = setBit(original, 2);

	// Set multiple bits
	uint8_t bit_list[2] = {1, 2};
	uint8_t n_bits = sizeof(bit_list);
	final = setBits(original, bit_list, n_bits);

	// Clear bit
	final = clearBit(original, 3);

	// Clear multiple bits
	uint8_t bit_list[2] = {0, 3};
	uint8_t n_bits = sizeof(bit_list);
	final = clearBits(original, bit_list, n_bits);

	// Toggle bit
	final = toggleBit(original, 1);

	// Toggle multiple bits
	uint8_t bit_list[2]= {0, 1};
	uint8_t n_bits = sizeof(bit_list);
	final = toggleBits(original, bit_list, n_bits);
	bitset<8> f(final);
	cout << f << endl;
*/

	// Check if bit is set
	cout << checkBit(original, 1) << endl;

	return 0;
}

