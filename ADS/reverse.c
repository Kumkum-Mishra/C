#include<stdio.h>
int main(){
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int temp[n];
    int k=0;
    for(int j=n-1;j>=0;j--){
      temp[k]=arr[j];
      k++;
    }
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
        printf("%d\n",arr[i]);
    }
    return 0;
}