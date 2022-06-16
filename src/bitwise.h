/*
 * bitwise.h
 *
 *  Created on: Sep 1, 2019
 *      Author: Bryan
 */

#ifndef BITWISE_H_
#define BITWISE_H_

#include <stdint.h>
#include <string.h>			// for memcpy

uint8_t setBit(uint8_t& input, uint8_t bit);
uint8_t setBits(uint8_t& input, uint8_t* bits, uint8_t n_bits);
uint8_t setMask(uint8_t& input, uint8_t mask, uint8_t msb, uint8_t lsb);
uint8_t clearBit(uint8_t& input, uint8_t bit);
uint8_t clearBits(uint8_t& input, uint8_t bits);
uint8_t clearBits(uint8_t& input, uint8_t* bits, uint8_t n_bits);
uint8_t toggleBit(uint8_t& input, uint8_t bit);
uint8_t toggleBits(uint8_t& input, uint8_t* bits, uint8_t n_bits);
bool checkBit(uint8_t& input, uint8_t bit);
bool checkBit(uint8_t& intput, uint8_t bit);
int twosComplement(uint8_t num);

// Converting Arrays of Bytes (uint8_t) to Numbers
uint16_t bytesToUint16(uint8_t* byte_array);
uint32_t bytesToUint32(uint8_t* byte_array);
int8_t byteToInt8(uint8_t byte_array);
int16_t bytesToInt16(uint8_t* byte_array);
int32_t bytesToInt32(uint8_t* byte_array);
int bytesToInt(uint8_t* byte_array);
float bytesToFloat(uint8_t* byte_array);

template <typename T> T bytesToInt(uint8_t* byte_array, T& my_int) {
    int n_bytes = sizeof(my_int);
	uint32_t temp = byte_array[0];
	
	for (int ii = 1; ii < n_bytes; ii++) temp = temp << 8 | byte_array[ii];
	my_int = temp;

	return my_int;
}

// Converting Numbers into Arrays of Bytes
void int16ToBytes(int16_t my_int, uint8_t* byte_array);
void int32ToBytes(int32_t my_int, uint8_t* byte_array);
//void intToBytes(int my_int, uint8_t* byte_array);
void floatToBytes(float my_float, uint8_t* byte_array);

template <typename T> void intToBytes(T& my_int, uint8_t* byte_array) {
	int n_bytes = sizeof(T);
	int shift;

	uint32_t temp = my_int;

	for(int ii = 0; ii < n_bytes; ii++){
		shift = 8*(n_bytes-1) - 8*(ii);
		byte_array[ii] = (temp >> shift) & 0xFF;
	}
}

#endif /* BITWISE_H_ */
