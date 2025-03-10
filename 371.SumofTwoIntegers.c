#include <stdio.h>

int getSum(int a, int b) {
    while (b != 0) {
        int sum = a ^ b;       // XOR: Sum without carry
        int carry = (a & b) << 1;  // AND: Carry shifted left
        
        a = sum;   // Update a to sum
        b = carry; // Update b to carry
    }
    return a;
}

int main() {
    int a = 1, b = 2;
    printf("Sum: %d\n", getSum(a, b));

    a = -2, b = 3;
    printf("Sum: %d\n", getSum(a, b));

    return 0;
}
