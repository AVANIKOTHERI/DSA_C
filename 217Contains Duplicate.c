#include <stdio.h>

#define HASH_SIZE 100000  // Define a large hash size for uniqueness tracking

// Function to check if array contains duplicates
int containsDuplicate(int nums[], int size) {
    static int hashTable[HASH_SIZE] = {0};  // Static array for tracking occurrences

    // Reset hash table before use (important for multiple calls)
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int index = abs(nums[i]) % HASH_SIZE;  // Hash function (mod operation)

        if (hashTable[index] == 1) {  // If the number is already seen, return true
            return 1;
        }

        hashTable[index] = 1;  // Mark the number as seen
    }

    return 0;  // No duplicates found
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int size = sizeof(nums) / sizeof(nums[0]);

    if (containsDuplicate(nums, size))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
