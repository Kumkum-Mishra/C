// program to find the addresses of the array in hexadecimal and decimal

#include <stdio.h>

int main() {
    int m, n;
    int i, j;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &m, &n);

    int arr[m][n]; 
    printf("\nEnter the elements in the array: \n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nThe array you entered is:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", arr[i][j]); // Added a space for readability
        }
        printf("\n");
    }

   printf("\nThe address of each element (Hexadecimal and Decimal):\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            // Using %p for hexadecimal address and casting to unsigned long for decimal
            printf("%p   (%lu) ", (void *)&arr[i][j], (unsigned long)&arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
Enter the number of rows and columns: 3
3

Enter the elements in the array: 
5
8
7
4
9
6
2
3
1

The array you entered is:
5 8 7
4 9 6
2 3 1

The address of each element (Hexadecimal and Decimal):
0061FE9C   (6422172) 0061FEA0   (6422176) 0061FEA4   (6422180)
0061FEA8   (6422184) 0061FEAC   (6422188) 0061FEB0   (6422192)
0061FEB4   (6422196) 0061FEB8   (6422200) 0061FEBC   (6422204)*/