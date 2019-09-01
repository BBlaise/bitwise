/*
 * bitwise.h
 *
 *  Created on: Sep 1, 2019
 *      Author: Bryan
 */

#ifndef BITWISE_H_
#define BITWISE_H_

#include <stdint.h>
#include <stdbool.h>

uint8_t setBit(uint8_t input, uint8_t bit);
uint8_t setBits(uint8_t input, uint8_t* bits, uint8_t n_bits);
uint8_t clearBit(uint8_t input, uint8_t bit);
uint8_t clearBits(uint8_t input, uint8_t* bits, uint8_t n_bits);
uint8_t toggleBit(uint8_t input, uint8_t bit);
uint8_t toggleBits(uint8_t input, uint8_t* bits, uint8_t n_bits);
bool checkBit(uint8_t intput, uint8_t bit);

#endif /* BITWISE_H_ */
