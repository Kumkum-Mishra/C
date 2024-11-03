#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter the length of the string: ");
    scanf("%d", &n);
    
    char input[n + 1];
    printf("Enter the string: ");
    scanf("%s", input);
    
    char result[2 * n + 1];
    int i = 0, j = 0, count = 0;
    
    while (input[i] != '\0') {
        result[j++] = input[i];
        count = (input[i++] == '1') ? count + 1 : 0;
        if (count == 5) {
            result[j++] = '0';
            count = 0;
        }
    }
    
    result[j] = '\0';
    printf("Modified string: %s\n", result);
    
    return 0;
}