#include <stdio.h>
#include <string.h>

int main() {
    char frame[100], str[50][50];
    char flag = 'z';  // Flag character for byte stuffing
    char esc = 'x';   // Escape character for byte stuffing
    int i, j, k = 0, n;

    // Initialize the frame with the flag character at the beginning
    frame[k++] = flag;

    // Taking input for the number of strings
    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar();  // To consume newline left by scanf

    // Input the strings
    printf("Enter the strings:\n");
    for (i = 0; i < n; i++) {
        fgets(str[i], sizeof(str[i]), stdin);
        str[i][strcspn(str[i], "\n")] = 0;  // Remove newline character from each string
    }

    // Display the entered strings
    printf("\nYou entered:\n");
    for (i = 0; i < n; i++) {
        puts(str[i]);
    }

    // Perform byte stuffing on the sender's side
    for (i = 0; i < n; i++) {
        for (j = 0; j < strlen(str[i]); j++) {
            if (str[i][j] != flag && str[i][j] != esc) {
                frame[k++] = str[i][j];  // Normal character, add to frame
            } else {
                frame[k++] = esc;  // Escape the character
                frame[k++] = str[i][j];  // Add the actual flag or escape character after escape
            }
        }
    }

    // Append the flag character at the end of the frame
    frame[k++] = flag;
    frame[k] = '\0';  // Null-terminate the frame

    // Display the byte-stuffed frame at the sender's side
    printf("\n---\n");
    printf("Byte stuffing at sender side:\n");
    printf("---\n");
    printf("%s\n", frame);

    // Byte unstuffing at the receiver's side
    printf("\nByte unstuffing at receiver side:\n\n");
    for (i = 1; i < k - 1; i++) {  // Skip the flag at the beginning and end
        if (frame[i] == esc) {
            i++;  // Skip the escape character and print the actual character
        }
        printf("%c", frame[i]);
    }

    printf("\n");
    return 0;
}
