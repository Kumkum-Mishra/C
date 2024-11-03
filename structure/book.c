#include<stdio.h>
#include<string.h>
int main()
{
    struct book{
        char name[50];
        float price;
        int no_of_pages;
    }book1,book2,book3;

        book1.price=445.6f;
        book1.no_of_pages=500;
        strcpy(book1.name,"the times of india");

        book2.price=567.4f;
        book2.no_of_pages=650;
        strcpy(book2.name,"secret seven");

        book3.price=578.3f;
        book3.no_of_pages=600;
        strcpy(book3.name,"rings of fire");

        printf("%d\n",book1.no_of_pages);
        printf("%f\n",book1.price);
        printf("%s\n",book1.name);

        printf("%d\n",book2.no_of_pages);
        printf("%f\n",book2.price);
        printf("%s\n",book2.name);

        printf("%d\n",book3.no_of_pages);
        printf("%f\n",book3.price);
        printf("%s",book3.name);
        

}