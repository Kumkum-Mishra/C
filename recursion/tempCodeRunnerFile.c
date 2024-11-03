#include<stdio.h>
int fibo(int m)
{
    if (m==1|| m==2)
    return 1;
    int ans1=fibo(m-1);
    int ans2=fibo(m-2);
    int f=ans1+ans2;
    //return fibo(n-1)+ fibo(n-2);
    return f;
    