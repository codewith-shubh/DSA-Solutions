
#include <stdlib.h>

void merge(int* nums, int left, int mid, int right, int* temp) {
    int i = left;
    int j = mid + 1;
    int k = left;

    // Merge the two sorted halves
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    // Copy remaining elements from the left half
    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    // Copy remaining elements from the right half
    while (j <= right) {
        temp[k++] = nums[j++];
    }

    // Copy merged elements back to the original array
    for (i = left; i <= right; i++) {
        nums[i] = temp[i];
    }
}

void mergeSort(int* nums, int left, int right, int* temp) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(nums, left, mid, temp);
    mergeSort(nums, mid + 1, right, temp);

    merge(nums, left, mid, right, temp);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    if (numsSize <= 1) {
        return nums;
    }

    int* temp = (int*)malloc(numsSize * sizeof(int));

    if (temp == NULL) {
        *returnSize = 0;
        return NULL;
    }

    mergeSort(nums, 0, numsSize - 1, temp);

    free(temp);
    return nums;
}
