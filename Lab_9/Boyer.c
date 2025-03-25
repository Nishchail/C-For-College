#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define NO_OF_CHARS 256

int opcount = 0; // Operation count

// Function to compute the bad character heuristic table
void badCharHeuristic(char *pattern, int patLen, int badChar[NO_OF_CHARS]) {
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
        badChar[i] = -1; // Initialize all occurrences as -1

    for (i = 0; i < patLen; i++)
        badChar[(int)pattern[i]] = i; // Store last occurrence of each character
}

// Boyer-Moore String Search Algorithm
int BoyerMooreSearch(char *text, char *pattern) {
    int txtLen = strlen(text);
    int patLen = strlen(pattern);
    int badChar[NO_OF_CHARS];

    // Preprocess the pattern to build the bad character heuristic table
    badCharHeuristic(pattern, patLen, badChar);

    int shift = 0; 
    int keyComparisons = 0;
    int found = 0; // Flag to check if at least one match is found

    while (shift <= (txtLen - patLen)) {
        int j = patLen - 1;

        // Compare from the last character of pattern
        while (j >= 0 && pattern[j] == text[shift + j]) {
            keyComparisons++;
            j--;
        }

        if (j < 0) { // If pattern is found
            printf("Pattern found at index %d\n", shift);
            found = 1;
            shift += (shift + patLen < txtLen) ? patLen - badChar[text[shift + patLen]] : 1;
        } else {
            keyComparisons++; // Count last failed comparison
            shift += (j - badChar[text[shift + j]] > 1) ? j - badChar[text[shift + j]] : 1;
        }

        opcount++; // Count operation
    }

    if (!found)
        printf("Pattern not found\n");

    return keyComparisons;
}

int main() {
    char text[1000], pattern[100];

    printf("Enter the text: ");
    scanf("%[^\n]%*c", text);  // Read entire line including spaces

    printf("Enter the pattern: ");
    scanf("%[^\n]%*c", pattern);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int keyComparisons = BoyerMooreSearch(text, pattern);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Total key comparisons: %d\n", keyComparisons);
    printf("Total operations (Opcount): %d\n", opcount);
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
