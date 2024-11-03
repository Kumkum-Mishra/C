#include <stdio.h>

int maxSubArraySum(int* nums, int numsSize) {
    int max_sum = nums[0];       
    int current_sum = nums[0];   

    for (int i = 1; i < numsSize; i++) {
       
        if (nums[i] > current_sum + nums[i]) {
            current_sum = nums[i];
        } else {
            current_sum = current_sum + nums[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    return max_sum;
}

int main() {
    int nums1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Maximum subarray sum is %d\n", maxSubArraySum(nums1, size1));  

    int nums2[] = {1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Maximum subarray sum is %d\n", maxSubArraySum(nums2, size2));  

    int nums3[] = {5, 4, -1, 7, 8};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Maximum subarray sum is %d\n", maxSubArraySum(nums3, size3));  

    return 0;
}
