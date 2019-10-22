/*
 * bitwise.cpp
 *
 *  Created on: Sep 1, 2019
 *      Author: Bryan
 */

//TODO
// - Accept references where possible

#include "bitwise.h"

#include <stdint.h>
#include <stdbool.h>

uint8_t setBit(uint8_t& input, uint8_t bit){
	uint8_t output = input | (1UL << bit);
	return output;
}

uint8_t setBits(uint8_t& input, uint8_t* bits, uint8_t n_bits){
	uint8_t mask = 0;
	for(int ii = 0; ii < n_bits; ii++){
		mask |= 1UL << bits[ii];
	}
	uint8_t output = input | mask;
	return output;
}

uint8_t setMask(uint8_t& input, uint8_t mask, uint8_t msb, uint8_t lsb){
    uint8_t output = input;
	for(int ii = msb; ii > (lsb-1); ii--){		// clear bits
		output &= ~(1UL << ii);
		//output = clearBit(output, ii);
	}

	output |= (mask << lsb);
	return output;
}

uint8_t clearBit(uint8_t& input, uint8_t bit){
	uint8_t output = input;
	output &= ~(1UL << bit);
	return output;
}

uint8_t clearBits(uint8_t& input, uint8_t* bits, uint8_t n_bits){
	uint8_t mask = 0;
	for(int ii = 0; ii < n_bits; ii++){
		mask |= 1UL << bits[ii];
	}
	uint8_t output = input & ~mask;
	return output;
}

uint8_t toggleBit(uint8_t& input, uint8_t bit){
	uint8_t output = input ^(1UL << bit);
	return output;
}

uint8_t toggleBits(uint8_t& input, uint8_t* bits, uint8_t n_bits){
	uint8_t mask = 0;
	for(int ii = 0; ii < n_bits; ii++){
		mask |= 1UL << bits[ii];
	}
	uint8_t output = input ^ mask;
	return output;
}

bool checkBit(uint8_t& input, uint8_t bit){
	bool is_set = false;
	if((input >> bit) & 1UL){
		is_set = true;
	};
	return is_set;
}

extern uint8_t twosComplement(uint8_t num){
    return -(unsigned int)num;
}
