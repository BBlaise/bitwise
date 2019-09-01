/*
 * bitwise.cpp
 *
 *  Created on: Sep 1, 2019
 *      Author: Bryan
 */

#include "bitwise.h"

#include <stdint.h>
#include <stdbool.h>

uint8_t setBit(uint8_t input, uint8_t bit){
	uint8_t output = input | (1UL << bit);
	return output;
}

uint8_t setBits(uint8_t input, uint8_t* bits, uint8_t n_bits){
	uint8_t mask = 0;
	for(int ii = 0; ii < n_bits; ii++){
		mask |= 1UL << bits[ii];
	}
	uint8_t output = input | mask;
	return output;
}

uint8_t clearBit(uint8_t input, uint8_t bit){
	uint8_t output = input & ~(1UL << bit);
	return output;
}

uint8_t clearBits(uint8_t input, uint8_t* bits, uint8_t n_bits){
	uint8_t mask = 0;
	for(int ii = 0; ii < n_bits; ii++){
		mask |= 1UL << bits[ii];
	}
	uint8_t output = input & ~mask;
	return output;
}

uint8_t toggleBit(uint8_t input, uint8_t bit){
	uint8_t output = input ^(1UL << bit);
	return output;
}

uint8_t toggleBits(uint8_t input, uint8_t* bits, uint8_t n_bits){
	uint8_t mask = 0;
	for(int ii = 0; ii < n_bits; ii++){
		mask |= 1UL << bits[ii];
	}
	uint8_t output = input ^ mask;
	return output;
}

bool checkBit(uint8_t input, uint8_t bit){
	bool is_set = false;
	if((input >> bit) & 1UL){
		is_set = true;
	};
	return is_set;
}
