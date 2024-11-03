#include<stdio.h>

int main(){
    int arr[7] = {3, 4, 9, 5, 6}; 
    int n = 5;  
    int k = 15, p = 7;

    n = n + 1;
    arr[n-1] = k;

    printf("Array elements after first insertion are:\t");
    for(int i = 0; i < n; i++){
        printf("%d\t",arr[i]);
    }

    for(int i = n; i > 1; i--) {
        arr[i] = arr[i-1];
    }
    arr[1] = p;
    n = n + 1;

    printf("\nArray elements after second insertion are:\t");
    for(int i = 0; i < n; i++){
        printf("%d\t",arr[i]);
    }

    return 0;
}
