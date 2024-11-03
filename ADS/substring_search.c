#include<stdio.h>
#include<string.h>

int main() {
    char text[] = "ShardaUniversity";
    char pattern[] = "University";
    int n = strlen(text);
    int m = strlen(pattern);
    int found = 0;

    for(int i = 0; i <= n - m; i++) {
        int j;
        for(j = 0; j < m; j++) {
            if(text[i + j] != pattern[j]) {  
                break;
            }
        }
        if(j == m) {  
            found = 1;
            printf("Pattern found at index %d\n", i);
        }
    }

    if(!found) {
        printf("Pattern not found in the text.\n");
    }

    return 0;
}
