#include <stdio.h>
#include <string.h>

#define MAX 100  // Maximum number of names
#define LEN 50   // Maximum length of each name

void bubbleSort(char names[][LEN], int n) {
    char temp[LEN];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

void printNames(char names[][LEN], int n) {
    printf("\nSorted Names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }
}

int main() {
    int n;
    char names[MAX][LEN];

    printf("Enter the number of names: ");
    scanf("%d", &n);
    
    // Input names
    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);  
    }

    bubbleSort(names, n);

    printNames(names, n);

    return 0;
}
