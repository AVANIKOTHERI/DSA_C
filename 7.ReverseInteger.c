#include <stdio.h>
#include <limits.h>  // For INT_MAX and INT_MIN

int reverse(int x) {
    int rev = 0;

    while (x != 0) {
        int digit = x % 10;  // Extract last digit

        // Check for overflow before updating rev
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) return 0;

        rev = rev * 10 + digit;  // Append digit
        x /= 10;  // Remove last digit
    }

    return rev;
}

int main() {
    int x;

    printf("Enter an integer: ");
    scanf("%d", &x);

    printf("Reversed integer: %d\n", reverse(x));
    return 0;
}
