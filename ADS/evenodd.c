#include<stdio.h>
int main() {
    int arr[]={1,2,3,4,5,6,7,8,9};
    int even_count=0,odd_count=0;
    int even_number[9],odd_number[9];
    int j=0,k=0;

    for(int i=0;i<9;i++){
    if(arr[i]%2==0) {
        even_number[j++]=arr[i];
        even_count++;
    }
    else {
        odd_number[k++]=arr[i];
        odd_count++;
    }
    }

    printf("Even count:%d",even_count);
    printf("\nOdd count:%d",odd_count);

    printf("\nEven Numbers:\n");
    for(int l=0;l<even_count;l++){
        printf("%d\t",even_number[l]);
    }
    printf("\nOdd Numbers:\n");
    for(int m=0;m<odd_count;m++){
        printf("%d\t",odd_number[m]);
    }
    return 0;

}