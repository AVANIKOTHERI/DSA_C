#include <stdio.h>

int missingNumber(int nums[], int n) {
    int missing = n;  // Start with n (since index goes up to n)

    for (int i = 0; i < n; i++) {
        missing ^= i ^ nums[i];  // XOR all indices and numbers
    }

    return missing;
}

int main() {
    int nums[] = {3, 0, 1};  // Example input
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Missing Number: %d\n", missingNumber(nums, n));
    return 0;
}
