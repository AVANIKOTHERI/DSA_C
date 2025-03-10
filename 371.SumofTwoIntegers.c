#include <stdio.h>

int getSum(int a, int b) {

    while (b != 0) {
        int sum = a ^ b;       // XOR: Sum without carry
        unsigned int carry = ((unsigned int)(a & b)) << 1;
        
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
