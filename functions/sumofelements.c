#include<stdio.h>
int sum(int x,int y)
{
    int s=x+y;
    return s;
}
int main()
{
    int a=5;
    int b=8;  
    int result=sum(a,b);
    printf("%d",result);
    return 0;
}

//sum using pointers
#include<stdio.h>
