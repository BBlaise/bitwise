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
	input |= (1UL << bit);
	return input;
}

uint8_t setBits(uint8_t& input, uint8_t* bits, uint8_t n_bits){
	uint8_t mask = 0;
	for(int ii = 0; ii < n_bits; ii++){
		mask |= 1UL << bits[ii];
	}
	input |= mask;
	return input;
}

uint8_t setMask(uint8_t& input, uint8_t mask, uint8_t msb, uint8_t lsb){
	for(int ii = msb; ii > (lsb-1); ii--){		// clear bits
		input &= ~(1UL << ii);
		//output = clearBit(output, ii);
	}

	input |= (mask << lsb);
	return input;
}

uint8_t clearBit(uint8_t& input, uint8_t bit){
	//uint8_t output = input;
	input &= ~(1UL << bit);
	return input;
}

uint8_t clearBits(uint8_t& input, uint8_t bits){
	int ii;
	for(ii = 0; ii < 8; ii++){
		if((bits >> ii) & 1 == 1){
			input &= ~(1UL << ii);
		}
	}
	return input;
}

uint8_t clearBits(uint8_t& input, uint8_t* bits, uint8_t n_bits){
	uint8_t mask = 0;
	for(int ii = 0; ii < n_bits; ii++){
		mask |= 1UL << bits[ii];
	}
	input &= ~mask;
	return input;
}

uint8_t toggleBit(uint8_t& input, uint8_t bit){
	input = input^ (1UL << bit);
	return input;
}

uint8_t toggleBits(uint8_t& input, uint8_t* bits, uint8_t n_bits){
	uint8_t mask = 0;
	for(int ii = 0; ii < n_bits; ii++){
		mask |= 1UL << bits[ii];
	}
	input = input ^ mask;
	return input;
}

bool checkBit(uint8_t& input, uint8_t bit){
	bool is_set = false;
	if((input >> bit) & 1UL){
		is_set = true;
	};
	return is_set;
}

extern int twosComplement(uint8_t num){
    //return -(unsigned int)num;
	return (int8_t)num;
}
