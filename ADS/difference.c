#include<stdio.h>
int main(){
    int arr[]={9,5,4,2,1};
    int diff=0;
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i=0;i<n-1;i++){
        diff=arr[i]-arr[i+1];
        printf("Difference of %d and %d is %d\n",arr[i],arr[i+1],diff);

    }
    return 0;
}