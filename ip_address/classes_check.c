#include<stdio.h>
int main(){
    int octal_A,octal_B,octal_C,octal_D;
    printf("Enter the octal number A: ");
    scanf("%d",&octal_A);

    printf("Enter the octal number B: ");
    scanf("%d",&octal_B);

    printf("Enter the octal number C: ");
    scanf("%d",&octal_C);

    printf("Enter the octal number D: ");
    scanf("%d",&octal_D);

    if(octal_A<=127 ||octal_A>=0){
        printf("Given Ip address belongs to Class_A");
    }

    else if(octal_A<=191 ||octal_A>=128){
        printf("Given Ip address belongs to Class_B");
    }

    else if(octal_A<=223 ||octal_A>=192){
        printf("Given Ip address belongs to Class_C");
    }

    else if(octal_A<=239 ||octal_A>=224){
        printf("Given Ip address belongs to Class_D");
    }

    else if(octal_A<=255 ||octal_A>=240){
        printf("Given Ip address belongs to Class_E");
    }

    else{
        printf("Given Ip address is invalid");
    }

    return 0;
}