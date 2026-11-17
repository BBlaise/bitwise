/*
 * Bitwise Utility Library
 *
 * This library provides a collection of functions for performing common bitwise operations and conversions between byte arrays and numeric types.
 * It is designed to simplify bit manipulation tasks and data serialization/deserialization in embedded and systems programming.

 * bitwise.h
 *
 *  Created on: Sep 1, 2019
 *      Author: Bryan
 */

#ifndef BITWISE_H_
#define BITWISE_H_

#include <stdint.h>
#include <string.h>			// for memcpy

// Set one bit (0 = LSB).
uint8_t setBit(uint8_t& input, uint8_t bit);

// Set bits by position (0 = LSB).
uint8_t setBits(uint8_t& input, uint8_t* bits, uint8_t n_bits);

// Write a right-aligned mask into bits msb through lsb. The mask must fit the field.
uint8_t setMask(uint8_t& input, uint8_t mask, uint8_t msb, uint8_t lsb);

// Clear one bit (0 = LSB).
uint8_t clearBit(uint8_t& input, uint8_t bit);

// Clear bits selected by the mask (1 = clear).
uint8_t clearBits(uint8_t& input, uint8_t bits);

// Clear bits by position (0 = LSB).
uint8_t clearBits(uint8_t& input, uint8_t* bits, uint8_t n_bits);

// Toggle one bit (0 = LSB).
uint8_t toggleBit(uint8_t& input, uint8_t bit);

// Toggle each listed bit once (0 = LSB).
uint8_t toggleBits(uint8_t& input, uint8_t* bits, uint8_t n_bits);

// Test one bit (0 = LSB).
bool checkBit(uint8_t& input, uint8_t bit);

// Interpret the byte as a two's-complement signed value.
int twosComplement(uint8_t num);


// Read two bytes, most significant first.
uint16_t bytesToUint16(uint8_t* byte_array);

// Read four bytes, most significant first.
uint32_t bytesToUint32(uint8_t* byte_array);

// Interpret the byte as a signed 8-bit value.
int8_t byteToInt8(uint8_t byte_array);

// Read two bytes, most significant first.
int16_t bytesToInt16(uint8_t* byte_array);

// Read four bytes, most significant first.
int32_t bytesToInt32(uint8_t* byte_array);

// Read sizeof(int) bytes, most significant first.
int bytesToInt(uint8_t* byte_array);

// Read sizeof(float) bytes in the target's native float representation.
float bytesToFloat(uint8_t* byte_array);

// Read sizeof(T) most-significant-byte-first bytes through a 32-bit accumulator.
template <typename T> T bytesToInt(uint8_t* byte_array, T& my_int) {
    int n_bytes = sizeof(my_int);
	uint32_t temp = byte_array[0];
	
	for (int ii = 1; ii < n_bytes; ii++) temp = temp << 8 | byte_array[ii];
	my_int = temp;

	return my_int;
}

// Convert a signed 8-bit value to its byte representation.
uint8_t int8ToByte(int8_t my_int);

// Write two bytes, most significant first.
void int16ToBytes(int16_t my_int, uint8_t* byte_array);

// Write four bytes, most significant first.
void int32ToBytes(int32_t my_int, uint8_t* byte_array);

// Write four bytes in the target's native float representation.
void floatToBytes(float my_float, uint8_t* byte_array);

// Take the low 32 bits of the value and write sizeof(T) bytes, most significant first.
template <typename T> void intToBytes(T& my_int, uint8_t* byte_array) {
	int n_bytes = sizeof(T);
	int shift;

	uint32_t temp = my_int;

	for(int ii = 0; ii < n_bytes; ii++){
		shift = 8*(n_bytes-1) - 8*(ii);  // Select the next byte from high to low.
		byte_array[ii] = (temp >> shift) & 0xFF;
	}
}

#endif /* BITWISE_H_ */
