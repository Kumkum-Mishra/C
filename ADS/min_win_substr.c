#include <stdio.h>
#include <string.h>

int main() {
    char text[] = "abcdefgh";
    char pattern[] = "abd";
    int n = strlen(text);
    int m = strlen(pattern);
    char result[10];
    int minLength = n + 1; 
    int resultIndex = 0;

    for (int i = 0; i <= n - m; i++) {
        int j;
        int k = i;
        int tempIndex = 0;

        char tempResult[10]; 

        for (j = 0; j < m && k < n; j++, k++) {
            tempResult[tempIndex++] = text[k];

            if (text[k] != pattern[j]) {
                j--;
            }
        }

        if (j == m) {
            tempResult[tempIndex] = '\0';

            if (tempIndex < minLength) {
                minLength = tempIndex;
                strcpy(result, tempResult);
                resultIndex = tempIndex;
            }
        }
    }

    result[resultIndex] = '\0'; 

    if (minLength <= n) {
        printf("Smallest window containing the pattern and in-between characters: %s\n", result);
    } else {
        printf("Pattern not found in the text.\n");
    }

    return 0;
}

