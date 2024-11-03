#include<stdio.h>
int powerlog(int m,int n)
{   if(n==0) return 1;
    int x=powerlog(m,n/2);
    if (n%2==0) //even case like 2^64=2^32*2^32
    { return x*x;
    }
    else // odd case like 2^5=2^2 * 2^2 * 2
    {
        return x*x*m;
    }
    }
int main()
{
    int a;
    printf("Enter base:");
    scanf("%d",&a);
    int b;
    printf("Enter power:");
    scanf("%d",&b);
    int p=powerlog(a,b);
    printf("%d",p);
    return 0;
}