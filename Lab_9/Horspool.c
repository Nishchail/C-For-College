#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256

int shiftTable[NO_OF_CHARS];
int keyComparisons = 0; // To count key comparisons

// Function to create shift table
void createShiftTable(char *pattern, int m) {
    for (int i = 0; i < NO_OF_CHARS; i++)
        shiftTable[i] = m; // Default shift length is pattern length
    
    for (int j = 0; j < m - 1; j++)
        shiftTable[(int)pattern[j]] = m - 1 - j;
}

// Horspool's string matching algorithm
int horspoolSearch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    createShiftTable(pattern, m);

    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            keyComparisons++;
            k++;
        }
        if (k == m)
            return i - m + 1; // Successful match
        keyComparisons++;
        i += shiftTable[(int)text[i]];
    }
    return -1; // Unsuccessful match
}

int main() {
    char text[100], pattern[100];
    printf("Enter the text: ");
    gets(text);
    printf("Enter the pattern: ");
    gets(pattern);
    
    keyComparisons = 0;
    int pos = horspoolSearch(text, pattern);
    if (pos != -1)
        printf("Pattern found at index %d\n", pos);
    else
        printf("Pattern not found in the text.\n");
    
    printf("Number of key comparisons: %d\n", keyComparisons);
    return 0;
}