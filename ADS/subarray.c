#include<stdio.h>

void subarray(int arr[], int start,int end) {
        int sum=0;
        for( int i=start;i<end;i++)
        {   
            printf("%d\t",arr[i]);
            sum=sum+arr[i];
        }
        printf("\nSum:%d",sum);
        }


int main() {
    int arr[]={1,2,3,4,5,6,7,8,9};
    subarray(arr,3,8);
    return 0;
}