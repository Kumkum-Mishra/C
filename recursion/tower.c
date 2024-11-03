/*#include<stdio.h>

void tower(int m, char s, char h, char d) {
    if (m == 0) {
        return;
    }
    tower(m - 1, s, d, h);
    for(int i=1;i<=100;i++){
    printf("%d.\t%c -> %c\n", i,s, d);
    }
    tower(m - 1, h, s, d);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    tower(n, 'a', 'b', 'c');
    return 0;
}*/
#include<stdio.h>

int step = 0;

void tower(int m, char s, char h, char d) {
    if (m == 0) {
        return;
    }
    tower(m - 1, s, d, h);
    step++;
    printf("%d. %c -> %c\n", step, s, d);
    tower(m - 1, h, s, d);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    tower(n, 'a', 'b', 'c');
    return 0;
}


// time complexity of this program is :
// O(2^n-1) where n is the number of disks or simply we can say O(2^n)
// so for n = 5  ,  it will take -> 2^5-1=31 steps
// time complxity is 2^5=32

