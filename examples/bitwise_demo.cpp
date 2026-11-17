// Set, check, and clear bit 2 in a byte.

#include <iostream>

#include "../src/bitwise.h"

// Print the byte after setting bit 2, then after clearing it.
int main() {
    uint8_t value = 0x09;
    constexpr uint8_t bit = 2;  // Count from the least significant bit.

    setBit(value, bit);
    std::cout << "After setting: " << static_cast<int>(value) << '\n';
    std::cout << "Bit is set: " << std::boolalpha << checkBit(value, bit) << '\n';

    clearBit(value, bit);
    std::cout << "After clearing: " << static_cast<int>(value) << '\n';
}
