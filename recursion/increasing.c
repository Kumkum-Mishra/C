//using extra parameter
#include<stdio.h>
void increasing(int m,int p)
{
    if ( m>p) // base case
    return ;
    printf("%d\n",m);
    increasing(m+1,p);
    return;
}
int main()
{
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    increasing(1,n);
    return 0;
}
