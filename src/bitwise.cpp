/*
 * Bitwise Utility Library
 *
 * This library implements functions for bit manipulation and conversion between byte arrays and numeric types.
 * It is intended to make low-level data handling and bit operations more accessible and reusable in C++ projects.

 * bitwise.cpp
 *
 *  Created on: Sep 1, 2019
 *      Author: Bryan
 */

//TODO
// - Accept references where possible

#include "bitwise.h"

// Set a single bit in the byte, counting from the least significant bit.
uint8_t setBit(uint8_t& input, uint8_t bit){
	input |= (1UL << bit);
	return input;
}

// Build a mask from the listed bit positions, then set those bits together.
uint8_t setBits(uint8_t& input, uint8_t* bits, uint8_t n_bits){
	uint8_t mask = 0;
	for(int ii = 0; ii < n_bits; ii++){
		mask |= 1UL << bits[ii];
	}
	input |= mask;
	return input;
}

// Clear bits from msb through lsb, then OR in the shifted mask.
uint8_t setMask(uint8_t& input, uint8_t mask, uint8_t msb, uint8_t lsb){
	for(int ii = msb; ii > (lsb-1); ii--){		// clear bits
		input &= ~(1UL << ii);
		//output = clearBit(output, ii);
	}

	input |= (mask << lsb);  // The shifted mask can extend past msb.
	return input;
}

// Clear a single bit in the byte, counting from the least significant bit.
uint8_t clearBit(uint8_t& input, uint8_t bit){
	//uint8_t output = input;
	input &= ~(1UL << bit);
	return input;
}

// Clear each input bit selected by a 1 in the supplied mask.
uint8_t clearBits(uint8_t& input, uint8_t bits){
	int ii;
	for(ii = 0; ii < 8; ii++){
		if( ((bits >> ii) & 1) == 1 ){
			input &= ~(1UL << ii);
		}
	}
	return input;
}

// Build a mask from the listed bit positions, then clear those bits together.
uint8_t clearBits(uint8_t& input, uint8_t* bits, uint8_t n_bits){
	uint8_t mask = 0;
	for(int ii = 0; ii < n_bits; ii++){
		mask |= 1UL << bits[ii];
	}
	input &= ~mask;
	return input;
}

// Flip a single bit with XOR.
uint8_t toggleBit(uint8_t& input, uint8_t bit){
	input = input^ (1UL << bit);
	return input;
}

// Combine the listed positions into a mask, then flip each selected bit once.
uint8_t toggleBits(uint8_t& input, uint8_t* bits, uint8_t n_bits){
	uint8_t mask = 0;
	for(int ii = 0; ii < n_bits; ii++){
		mask |= 1UL << bits[ii];
	}
	input = input ^ mask;
	return input;
}

// Report whether the selected bit is set.
bool checkBit(uint8_t& input, uint8_t bit){
	bool is_set = false;
	if((input >> bit) & 1UL){
		is_set = true;
	};
	return is_set;
}

// Convert the byte to int8_t before returning its value as int.
int twosComplement(uint8_t num) {
	// TODO for more than uint8_t to int8_t
    //return -(unsigned int)num;
	return (int8_t)num;
}

/*-----------------------------------------------------------*/
// Read two bytes in most-significant-byte-first order as an unsigned integer.
uint16_t bytesToUint16(uint8_t* byte_array) {
	int n_bytes = 2;
	uint16_t my_int = byte_array[0];
	for(int ii = 1; ii < n_bytes; ii++){
		my_int = my_int << 8 | byte_array[ii];
	}
	return my_int;
}
// Read four bytes in most-significant-byte-first order as an unsigned integer.
uint32_t bytesToUint32(uint8_t* byte_array) {
	int n_bytes = 4;
	uint32_t my_int = byte_array[0];
	for(int ii = 1; ii < n_bytes; ii++){
		my_int = my_int << 8 | byte_array[ii];
	}
	return my_int;
}

// Convert a byte to an 8-bit signed value.
int8_t byteToInt8(uint8_t my_byte){
	int8_t my_int = (int8_t)my_byte;
	return my_int;
}

// Combine two most-significant-byte-first bytes into a signed 16-bit value.
int16_t bytesToInt16(uint8_t* byte_array){
	int16_t my_int = byte_array[0] << 8 | byte_array[1];
	return my_int;
}

// Combine four most-significant-byte-first bytes into a signed 32-bit value.
int32_t bytesToInt32(uint8_t* byte_array){
	int32_t my_int = byte_array[0];
	for(int ii = 1; ii < 4; ii++) my_int = my_int << 8 | byte_array[ii];
	return my_int;
}

// Read sizeof(int) bytes in most-significant-byte-first order into an int.
int bytesToInt(uint8_t* byte_array){
	int n_bytes = sizeof(int);
	int my_int = byte_array[0];
	for(int ii = 1; ii < n_bytes; ii++) my_int = my_int << 8 | byte_array[ii];
	return my_int;
}

// Copy sizeof(float) bytes into a float using the target's native representation.
float bytesToFloat(uint8_t* byte_array){
    float my_float = 0;
    memcpy(&my_float, byte_array, sizeof(my_float));
    return my_float;
}


/*-----------------------------------------------------------*/
// Convert an 8-bit signed value to an unsigned byte.
uint8_t int8ToByte(int8_t my_int) {
	uint8_t my_byte = (uint8_t)my_int;
	return my_byte;
}

// Write a signed 16-bit value as two bytes, most significant first.
void int16ToBytes(int16_t my_int, uint8_t* byte_array){
    byte_array[0] = (my_int >> 8) & 0xFF;
    byte_array[1] = my_int & 0xFF;
}

// Write a signed 32-bit value as four bytes, most significant first.
void int32ToBytes(int32_t my_int, uint8_t* byte_array){
    byte_array[0] = (my_int >> 24) & 0xFF;
    byte_array[1] = (my_int >> 16) & 0xFF;
    byte_array[2] = (my_int >> 8) & 0xFF;
    byte_array[3] = my_int & 0xFF;
}

// Copy the first four bytes of the float's native representation.
void floatToBytes(float my_float, uint8_t* byte_array){
    union {
        float union_float_;
        uint8_t union_byte_array[4];
    } u;
    
    u.union_float_ = my_float; // Store the float in the union.
    memcpy(byte_array, u.union_byte_array, 4);    // Copy the four-byte union member into the output buffer.

}
