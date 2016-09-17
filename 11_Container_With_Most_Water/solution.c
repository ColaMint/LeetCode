#include <stdio.h>

int calArea(int* height, int l, int r) {
    int ly = height[l];
    int ry = height[r];
    return ly < ry ? (r - l) * ly : (r - l) * ry;
}

int maxArea(int* height, int heightSize) {
    int l = 0;
    int r = heightSize - 1;
    int maxArea = calArea(height, l, r);
    int curArea;
    while (l < r - 1) {
        if (height[l] < height[r]) {
            ++l;
        } else {
            --r;
        }
        printf("%d %d\n", l, r);
        curArea = calArea(height, l, r);
        if (curArea > maxArea) {
            maxArea = curArea;
        }
    }
    return maxArea;
}

int main() {
    int a[7] = {2, 3, 10, 5, 7, 8, 9};
    printf("%d\n", maxArea(a, 7));
}
