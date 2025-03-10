#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;

    for (int i = 0; i < 32; i++) {
        result = (result << 1) | (n & 1);  // Shift left and add LSB of n
        n >>= 1;  // Move to the next bit
    }

    return result;
}

int main() {
    uint32_t num = 43261596;  // Example input
    printf("Reversed bits: %u\n", reverseBits(num));
    return 0;
}
