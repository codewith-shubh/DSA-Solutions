int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            // Minimum is to the right of mid
            left = mid + 1;
        }
        else if (nums[mid] < nums[right]) {
            // Minimum is at mid or to the left
            right = mid;
        }
        else {
            // nums[mid] == nums[right]
            // Can't determine which side contains minimum
            right--;
        }
    }

    return nums[left];
}
