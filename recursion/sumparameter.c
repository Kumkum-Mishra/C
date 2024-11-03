// print sum from n to 1
#include<stdio.h>
void sum(int m,int s)
{
    if ( m==0) // base case
    {
        printf("%d",s);
    return ;
    }
    sum(m-1,s+m);
    return;
}
int main()
{
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    sum(n,0);
    return 0;
}