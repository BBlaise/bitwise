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
#include <string.h>			// for memcpy

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
		if( ((bits >> ii) & 1) == 1 ){
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

int twosComplement(uint8_t num) {
	// TODO for more than uint8_t to int8_t
    //return -(unsigned int)num;
	return (int8_t)num;
}

/*-----------------------------------------------------------*/
// Converting Arrays of Bytes (uint8_t) to Numbers
uint16_t bytesToUint16(uint8_t* byte_array) {
	int n_bytes = 2;
	uint16_t my_int = byte_array[0];
	for(int ii = 1; ii < n_bytes; ii++){
		my_int = my_int << 8 | byte_array[ii];
	}
	return my_int;
}
uint32_t bytesToUint32(uint8_t* byte_array) {
	int n_bytes = 4;
	uint32_t my_int = byte_array[0];
	for(int ii = 1; ii < n_bytes; ii++){
		my_int = my_int << 8 | byte_array[ii];
	}
	return my_int;
}



int8_t byteToInt8(uint8_t my_byte){
	int8_t my_int = (int8_t)my_byte;
	return my_int;
}

int16_t bytesToInt16(uint8_t* byte_array){
	int16_t my_int = byte_array[0] << 8 | byte_array[1];
	return my_int;
}

int32_t bytesToInt32(uint8_t* byte_array){
	int32_t my_int = byte_array[0];
	for(int ii = 1; ii < 4; ii++) my_int = my_int << 8 | byte_array[ii];
	return my_int;
}

int bytesToInt(uint8_t* byte_array){
	int n_bytes = sizeof(int);
	int my_int = byte_array[0];
	for(int ii = 1; ii < n_bytes; ii++) my_int = my_int << 8 | byte_array[ii];
	return my_int;
}

float bytesToFloat(uint8_t* byte_array){
    float my_float = 0;
    memcpy(&my_float, byte_array, sizeof(my_float));
    return my_float;
}


/*-----------------------------------------------------------*/
// Converting Numbers into Arrays of Bytes
// void intToBytes(int my_int, uint8_t* byte_array) {
// 	int n_bytes = sizeof(my_int);
// 	int shift;

// 	for(int ii = 0; ii < n_bytes; ii++){
// 		shift = 8*(n_bytes-1) - 8*(ii);
// 		byte_array[ii] = (my_int >> shift) & 0xFF;
// 	}
// }

uint8_t int8ToByte(int8_t my_int) {
	uint8_t my_byte = (uint8_t)my_int;
	return my_byte;
}

void int16ToBytes(int16_t my_int, uint8_t* byte_array){
    byte_array[0] = (my_int >> 8) & 0xFF;
    byte_array[1] = my_int & 0xFF;
}

void int32ToBytes(int32_t my_int, uint8_t* byte_array){
    byte_array[0] = (my_int >> 24) & 0xFF;
    byte_array[1] = (my_int >> 16) & 0xFF;
    byte_array[2] = (my_int >> 8) & 0xFF;
    byte_array[3] = my_int & 0xFF;
}

void floatToBytes(float my_float, uint8_t* byte_array){
    union {
        float union_float_;
        uint8_t union_byte_array[4];
    } u;
    
    u.union_float_ = my_float;// Overite bytes of union with float variable
    memcpy(byte_array, u.union_byte_array, 4);    // Assign bytes to input array

}
