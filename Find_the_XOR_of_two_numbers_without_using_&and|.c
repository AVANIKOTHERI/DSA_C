#include <stdio.h>

int simulateXOR(int a, int b) {
    return (a | b) & ~(a & b);
}

int main() {
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    printf("XOR of %d and %d is: %d\n", x, y, simulateXOR(x, y));

    return 0;
}
