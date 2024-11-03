#include<stdio.h>
void decreasing(int m)
{
    if ( m==0) // base case
    return ;
    printf("%d\n",m);
    decreasing(m-1);
    return;
}
int main()
{
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    decreasing(n);
    return 0;
}