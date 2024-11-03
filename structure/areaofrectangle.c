#include<stdio.h>
#include<stdlib.h>
struct rectangle{
    int length;
    int breadth;
};
int main()
{
   struct rectangle r1={20,28};//we can initialize in this way also
   r1.length=12;
   r1.breadth=25;
   printf("Area of rectangle:%d",r1.length*r1.breadth);
   return 0;
}