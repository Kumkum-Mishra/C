#include <stdio.h>

int maxCoins(int* nums, int numsSize) {
    // Including virtual balloons with 1 painted on them at both ends
    int n = numsSize + 2;
    int newNums[n];

    // Fill the new array with the numbers and 1s at both ends
    newNums[0] = 1;
    newNums[n - 1] = 1;
    for (int i = 1; i <= numsSize; i++) {
        newNums[i] = nums[i - 1];
    }

    // DP array to store maximum coins that can be obtained for a range
    int dp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill the DP array
    for (int len = 2; len < n; len++) { // len is the length of the range
        for (int left = 0; left < n - len; left++) {
            int right = left + len;
            for (int i = left + 1; i < right; i++) {
                int sum = newNums[left] * newNums[i] * newNums[right];
                sum += dp[left][i] + dp[i][right];
                if (sum > dp[left][right]) {
                    dp[left][right] = sum;
                }
            }
        }
    }

    // The result is in dp[0][n-1]
    return dp[0][n-1];
}

int main() {
    int nums[] = {3, 1, 5, 8}; // Example array
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Maximum coins: %d\n", maxCoins(nums, numsSize));
    return 0;
}
