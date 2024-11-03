#include <stdio.h>
// function prototype
int fibonacci(int term);

int main() {
    int terms, i;
    
    printf("Enter the number of terms: ");
    scanf("%d", &terms);
    
    printf("Fibonacci Series:\n");
    for(i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    
    return 0;
}

int fibonacci(int term) {
    if(term == 0)
        return 0; // Base case for 0
    else if(term == 1)
        return 1; // Base case for 1
    else
        return fibonacci(term - 1) + fibonacci(term - 2);
}
