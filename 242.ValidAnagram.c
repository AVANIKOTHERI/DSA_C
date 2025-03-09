#include <stdio.h>
#include <string.h>

#define CHAR_SIZE 256  // ASCII character set size

// Function to check if two strings are anagrams
int isAnagram(char s[], char t[]) {
    int freq[CHAR_SIZE] = {0};  // Initialize frequency array

    // If lengths are different, not anagrams
    if (strlen(s) != strlen(t))  
        return 0;

    // Count character occurrences in s
    for (int i = 0; s[i] != '\0'; i++) {
        freq[(unsigned char)s[i]]++;  // Increment count for s
        freq[(unsigned char)t[i]]--;  // Decrement count for t
    }

    // Check if all counts are zero
    for (int i = 0; i < CHAR_SIZE; i++) {
        if (freq[i] != 0) 
            return 0;
    }

    return 1;
}

int main() {
    char s[] = "racecar";
    char t[] = "carrace";

    if (isAnagram(s, t))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
