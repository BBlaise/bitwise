# bitwise

Small C++ helpers for setting, clearing, toggling, and checking bits in a byte and converting between byte arrays and numeric values.

## Install

Add [src/bitwise.h](src/bitwise.h) and [src/bitwise.cpp](src/bitwise.cpp) to your project. Include the header and compile and link the source with your application. There are no external dependencies.

## Usage

```cpp
#include "bitwise.h"

int main() {
    uint8_t value = 0x09;
    setBit(value, 2);  // value becomes 0x0D. Bit 0 is the least significant bit.
}
```

## Examples

- [Bit manipulation](examples/bitwise_demo.cpp) — Set, check, and clear a bit in a byte.
- [Integer to bytes](examples/integer_bytes.cpp) — Write a 16-bit value as two bytes, most significant first, and read it back.

## License

[MIT License](LICENSE.md)
