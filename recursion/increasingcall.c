#include<stdio.h>
void increasing(int m)
{
    if ( m==0) // base case
    return ;
    increasing(m-1);
    printf("%d\n",m);
    return;
}
int main()
{
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    increasing(n);
    return 0;
}