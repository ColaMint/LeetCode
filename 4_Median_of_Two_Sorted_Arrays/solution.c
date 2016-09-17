#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2,
                              int nums2Size) {
    int mid1 = 0, mid2 = 0;
    int mid1Index, mid2Index;
    int dropIndex;
    int diff;
    int *tmpNums, tmpNumsSize;

    if (((nums1Size + nums2Size) & 1) == 0) {
        mid1Index = (nums1Size + nums2Size - 1) / 2;
        mid2Index = mid1Index + 1;
    } else {
        mid1Index = mid2Index = (nums1Size + nums2Size - 1) / 2;
    }

    while (1) {
        if (nums1Size == 0) {
            if (mid1Index >= 0) {
                mid1 = nums2[mid1Index];
            }
            mid2 = nums2[mid2Index];
            break;
        }

        if (nums2[0] < nums1[0]) {
            tmpNums = nums1;
            nums1 = nums2;
            nums2 = tmpNums;
            tmpNumsSize = nums1Size;
            nums1Size = nums2Size;
            nums2Size = tmpNumsSize;
        }

        dropIndex = nums1Size - 1;
        while (dropIndex > 0) {
            if (nums1[dropIndex] <= nums2[0]) {
                break;
            }
            dropIndex >>= 1;
        }
        if (mid1Index >= 0 && mid1Index <= dropIndex) {
            mid1 = nums1[mid1Index];
        }
        if (mid2Index >= 0 && mid2Index <= dropIndex) {
            mid2 = nums1[mid2Index];
            break;
        }
        diff = dropIndex + 1;
        mid1Index -= diff;
        mid2Index -= diff;
        nums1 += diff;
        nums1Size -= diff;
    }

    return (mid1 + mid2) / 2.0;
}

int main() {
    int a[] = {1, 2, 2};
    int b[] = {1, 2, 3};
    printf("%f\n", findMedianSortedArrays(a, 3, b, 3));
}
