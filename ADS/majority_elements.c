#include<stdio.h>

int main() {
    int arr[] = {1, 1, 4, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_count = 0, majority_element = -1;

    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
        if(count > max_count) {
            max_count = count;
            majority_element = arr[i];
        }
    }

    if(max_count > n/2) {
        printf("The majority element is %d\n", majority_element);
    } else {
        printf("There is no majority element\n");
    }

    printf("Frequency of each element:\n");
    int visited[n];
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    for(int i = 0; i < n; i++) {
        if(visited[i] == 1) continue; 

        int count = 0;
        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }

        printf("%d occurs %d times\n", arr[i], count);

        for(int k = i; k < n; k++) {
            if(arr[k] == arr[i]) {
                visited[k] = 1;
            }
        }
    }

    return 0;
}
