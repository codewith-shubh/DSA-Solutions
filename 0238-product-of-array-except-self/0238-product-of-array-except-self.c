int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* result = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    // Prefix product
    int prefix = 1;

    for (int i = 0; i < numsSize; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    // Suffix product
    int suffix = 1;

    for (int i = numsSize - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}
