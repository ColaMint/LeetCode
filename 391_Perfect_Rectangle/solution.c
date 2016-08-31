#include <memory>
#include <cstdio>
#include <cstdlib>
int pointCmp(const void* a, const void* b) {
    int* pa = *(int**)a;
    int* pb = *(int**)b;
    for (int i = 0; i < 2; ++i) {
        if (pa[i] < pb[i]) {
            return -1;
        }
        if (pa[i] > pb[i]) {
            return 1;
        }
    }
    return 0;
}

int rectangleCmp(const void* a, const void* b) {
    int* pa = *(int**)a;
    int* pb = *(int**)b;
    for (int i = 0; i < 4; ++i) {
        if (pa[i] < pb[i]) {
            return -1;
        }
        if (pa[i] > pb[i]) {
            return 1;
        }
    }
    return 0;
}

bool isRectangleCover(int** rectangles, int rectanglesRowSize,
                      int rectanglesColSize) {
    qsort(rectangles, rectanglesRowSize, sizeof(int*), rectangleCmp);
    for (int i = 1; i < rectanglesRowSize; ++i) {
        if (rectangles[i][0] >= rectangles[i - 1][0] &&
            rectangles[i][1] >= rectangles[i - 1][1] &&
            rectangles[i][0] < rectangles[i - 1][2] &&
            rectangles[i][1] < rectangles[i - 1][3]) {
            return false;
        }
    }

    int** points;
    int pointCnt = rectanglesRowSize * 4;
    points = (int**)malloc(pointCnt * sizeof(int*));
    for (int i = 0; i < pointCnt; ++i) {
        points[i] = (int*)malloc(2 * sizeof(int));
    }

    int pointIndex = 0;
    for (int i = 0; i < rectanglesRowSize; ++i) {
        int lx = rectangles[i][0];
        int ly = rectangles[i][1];
        int rx = rectangles[i][2];
        int ry = rectangles[i][3];
        points[pointIndex][0] = lx;
        points[pointIndex++][1] = ly;
        points[pointIndex][0] = rx;
        points[pointIndex++][1] = ry;
        points[pointIndex][0] = lx;
        points[pointIndex++][1] = ry;
        points[pointIndex][0] = rx;
        points[pointIndex++][1] = ly;
    }
    qsort(points, pointCnt, 2 * sizeof(int), pointCmp);

    int leftPoint = pointCnt;
    for (int i = 1; i < pointCnt;) {
        if (points[i][0] == points[i - 1][0] &&
            points[i][1] == points[i - 1][1]) {
            leftPoint -= 2;
            i += 2;
        } else {
            i += 1;
        }
    }
    return leftPoint == 4;
}

int main() {
    int** r = new int*[4];

    r[0] = new int[4];
    r[0][0] = 0;
    r[0][1] = 0;
    r[0][2] = 1;
    r[0][3] = 1;

    r[1] = new int[4];
    r[1][0] = 0;
    r[1][1] = 0;
    r[1][2] = 2;
    r[1][3] = 1;

    r[2] = new int[4];
    r[2][0] = 1;
    r[2][1] = 0;
    r[2][2] = 2;
    r[2][3] = 1;

    r[3] = new int[4];
    r[3][0] = 0;
    r[3][1] = 2;
    r[3][2] = 2;
    r[3][3] = 3;

    printf("%d\n", isRectangleCover(r, 4, 4));
    return 0;
}
