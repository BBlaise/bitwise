// Convert a positive 16-bit integer to two bytes and read it back.

#include <iostream>

#include "../src/bitwise.h"

// Print the encoded bytes in order and the decoded value.
int main() {
    uint8_t bytes[2];
    int16ToBytes(0x1234, bytes);

    std::cout << std::hex << "Bytes: 0x" << static_cast<int>(bytes[0])
              << " 0x" << static_cast<int>(bytes[1]) << '\n';
    std::cout << "Decoded: 0x" << bytesToUint16(bytes) << '\n';
}
