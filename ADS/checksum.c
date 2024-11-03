#include <stdio.h>

void checksum(int arr[], int size, int k)
{   
    int count = 0; // Initialize count
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == k)
            {   
                count++;
            }
        }
    }
    printf("Total possible ways: %d\n", count); 
    if (count == 0) {
        printf("False\n");
    }
}

int main()
{
    int arr[] = {2, 4, 6, 5, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k;

    printf("Enter the value of k: ");
    scanf("%d", &k);

    checksum(arr, size, k);

    return 0;
}
