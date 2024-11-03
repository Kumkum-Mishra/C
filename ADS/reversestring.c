#include <stdio.h>
#include <string.h>

void reverse(char *str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void reverseWords(char *str) {
    int length = strlen(str);

    reverse(str, 0, length - 1);

    int start = 0, end = 0;
    while (end <= length) {
        if (str[end] == ' ' || str[end] == '\0') {
            reverse(str, start, end - 1);
            start = end + 1;
        }
        end++;
    }
}

int main() {
    char str[] = "This is Sharda University";
    
    printf("Original string: %s\n", str);

    reverseWords(str);
    
    printf("Reversed string: %s\n", str);
    
    return 0;
}
