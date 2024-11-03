//anagram when two strings are equal but rearranged 
#include<stdio.h>
#include<string.h>

// Function to sort the characters in a string
void sortString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char S1[] = "anagram";
    char S2[] = "nagaram";

  
    sortString(S1);
    sortString(S2);

    // Compare the sorted strings
    if (strcmp(S1, S2) == 0) {
        printf("S1 and S2 are anagrams.\n");
    } else {
        printf("S1 and S2 are not anagrams.\n");
    }

    return 0;
}



/*#include<stdio.h>
#include<string.h>
int main(){
    char S1[20]="Sharda";
    char S2[20]="University";
    int n= strlen(S1);
    printf("Before Concatenation:\n");
    printf("%s\n",S1);
    strcat(S1,S2);
    printf("After Concatenation:\n");
    printf("%s\n",S1);
    char ext[20];
    strncpy(ext, S1, n); 
    ext[n] ='\0';           
    printf("%s\n",ext);
    return 0;
    }*/