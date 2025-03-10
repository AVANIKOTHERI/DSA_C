#include <stdio.h>
#include <stdlib.h>

int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;  // Set the size of the array
    int* ans = (int*)malloc((*returnSize) * sizeof(int));  // Allocate memory

    ans[0] = 0;  // Base case
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i >> 1] + (i & 1);
    }

    return ans;  // Return pointer to allocated memory
}

int main() {
    int size;
    int* result = countBits(5, &size);  // Call function

    printf("Output: [");
    for (int i = 0; i < size; i++) {
        printf("%d", result[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");

    free(result);  // Free allocated memory
    return 0;
}
