#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(numsSize * sizeof(int));
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        ans[i] = sum;
    }

    *returnSize = numsSize;
    return ans;
}