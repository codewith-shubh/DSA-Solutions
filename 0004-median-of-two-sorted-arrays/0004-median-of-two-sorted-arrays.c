#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size) {
    // Always binary-search the smaller array
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size,
                                      nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;

    int low = 0;
    int high = m;

    while (low <= high) {
        // Number of elements taken from nums1
        int partition1 = (low + high) / 2;

        // Number taken from nums2
        int partition2 = (m + n + 1) / 2 - partition1;

        int left1  = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int right1 = (partition1 == m) ? INT_MAX : nums1[partition1];

        int left2  = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int right2 = (partition2 == n) ? INT_MAX : nums2[partition2];

        // Correct partition
        if (left1 <= right2 && left2 <= right1) {
            if ((m + n) % 2 == 1) {
                return (double)(left1 > left2 ? left1 : left2);
            }

            int maxLeft = left1 > left2 ? left1 : left2;
            int minRight = right1 < right2 ? right1 : right2;

            return ((double)maxLeft + (double)minRight) / 2.0;
        }

        // nums1 partition is too far right
        if (left1 > right2) {
            high = partition1 - 1;
        }
        // nums1 partition is too far left
        else {
            low = partition1 + 1;
        }
    }

    return 0.0; // Should never be reached for valid input
}
