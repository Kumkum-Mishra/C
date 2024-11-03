#include <stdio.h>

int main() {
    char str[] = "Hello World";
    char current;
    int count;

    printf("Character frequency in \"%s\":\n", str);

    for (int i = 0; str[i] != '\0'; i++) {
        current = str[i];
        count = 0;

        int alreadyCounted = 0;
        for (int k = 0; k < i; k++) {
            if (str[k] == current) {
                alreadyCounted = 1;
                break;
            }
        }
        if (alreadyCounted) {
            continue;
        }

        for (int j = 0; str[j] != '\0'; j++) {
            if (str[j] == current) {
                count++;
            }
        }

        printf("%c: %d\n", current, count);
    }

    return 0;
}
