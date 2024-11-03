#include<stdio.h>
int power(int m,int n)
{   if(n==0)
    return 1;
    int pow=m*power(m,n-1);
    return pow; 
}
int main()
{
    int a;
    printf("Enter base:");
    scanf("%d",&a);
    int b;
    printf("Enter power:");
    scanf("%d",&b);
    int p=power(a,b);
    printf("%d",p);
    return 0;
}