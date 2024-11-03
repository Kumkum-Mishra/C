#include <stdio.h>
#include <string.h>

int main() {
    int i, j, count = 0, nl;
    char str[100];
    
    // Taking input
    printf("Enter the bit string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove trailing newline from fgets
    str[strcspn(str, "\n")] = 0;
    
    // Iterate through the string and check for five consecutive '1's
    for (i = 0; i < strlen(str); i++) {
        count = 0;
        
        // Check for consecutive '1's (up to 5)
        for (j = i; j < (i + 5) && j < strlen(str); j++) {
            if (str[j] == '1') {
                count++;
            }
        }
        
        // If there are five consecutive '1's, perform bit stuffing
        if (count == 5) {
            nl = strlen(str);
            
            // Shift the characters after the fifth '1' to the right to insert '0'
            for (j = nl; j >= (i + 5); j--) {
                str[j + 1] = str[j];
            }
            
            // Insert '0' after the five '1's
            str[i + 5] = '0';
            
            // Move index forward to skip the newly inserted bit and avoid infinite loop
            i += 5;
        }
    }
    
    // Output the stuffed bit string
    printf("Bit-stuffed string: %s\n", str);
    
    return 0;
}
