#include<stdio.h>
int factorial(int m)
{
    if (m==1 || m==0 ) // base case
    return 1;
    int recans = m*factorial(m-1);
    return recans;
}
int main()
{
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    int fact=factorial(n);
    printf("%d",fact);
    return 0;
}