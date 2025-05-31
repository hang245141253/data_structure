#include <iostream>
#include "sort_test.h"
#include <algorithm>
using namespace std;


void print(int *arr, int l, int r) {
    for (int i = l; i < r; i++) {
        printf("%d ", arr[i]);
    } putchar('\n');
}

// 区间是左闭右开的
void v0(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1)    return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }

    int x = l, y = r - 1;
    int z = arr[l]; // 这里的z是一个基准值

    while (x < y) {
        while (x < y && z <= arr[y]) y--;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= z) x++;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = z; // 这里的z是一个基准值
    // print(arr, l, r);
    v0(arr, l, x);
    v0(arr, x + 1, r);
    return ;
}

// 减少判断次数，对分区操作进行优化
void v1(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1)    return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }

    int x = l, y = r - 1;
    int z = arr[l]; // 这里的z是一个基准值

    do {
        while (arr[x] < z) x++;
        while (arr[y] > z) y--;
        if (x <= y) {
            swap(arr[x], arr[y]);
            x++, y--;
        }
    } while (x <= y);

    print(arr, l, r);
    v1(arr, l, y + 1);
    v1(arr, x, r);
    return ;
}

// 三点取中法
inline int three_point_select(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return b;
}

void v2(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1)    return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }

    int x = l, y = r - 1;
    int z = three_point_select(arr[l],
                               arr[r - 1], 
                               arr[(l + r) / 2]);

    do {
        while (arr[x] < z) x++;
        while (arr[y] > z) y--;
        if (x <= y) {
            swap(arr[x], arr[y]);
            x++, y--;
        }
    } while (x <= y);

    // print(arr, l, r);
    v2(arr, l, y + 1);
    v2(arr, x, r);
    return ;
}

void v3(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1)    return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }

    while (l < r) {
        int x = l, y = r - 1;
        int z = three_point_select(arr[l],
                                arr[r - 1], 
                                arr[(l + r) / 2]);

        do {
            while (arr[x] < z) x++;
            while (arr[y] > z) y--;
            if (x <= y) {
                swap(arr[x], arr[y]);
                x++, y--;
            }
        } while (x <= y);

        // print(arr, l, r);
        v3(arr, l, y + 1);  // 只有左边递归
        l = x;
        // 在本层循环实现右边的排序
    }
    return ;
}


// 这里的v4是对v3的改进

void unguarded_insert_sort(int *arr, int l, int r) {
    int ind = l;
    for (int i = l + 1; i < r; i++) {
        if (arr[i] < arr[ind]) ind = i;
    }
    while (ind > l) {
        swap(arr[ind], arr[ind - 1]);
        ind -= 1;
    }

    for (int i = l + 1; i < r; i++) {
        int j = i;
        while (arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j -= 1;
        }
    }
}
#define threshold 16
void __v4(int *arr, int l, int r) {
    while (r - l > threshold) {
        int x = l, y = r - 1;
        int z = three_point_select(arr[l],
                                arr[r - 1], 
                                arr[(l + r) / 2]);

        do {
            while (arr[x] < z) x++;
            while (arr[y] > z) y--;
            if (x <= y) {
                swap(arr[x], arr[y]);
                x++, y--;
            }
        } while (x <= y);

        // print(arr, l, r);
        __v4(arr, l, y + 1);  // 只有左边递归
        l = x;
        // 在本层循环实现右边的排序
    }
    return ;
}

void v4(int *arr, int l, int r) {
    __v4(arr, l, r);
    unguarded_insert_sort(arr, l, r);
    return ;
}


int main() {
    int arr[] = {5, 3, 8, 9, 4, 6, 7, 5};
    // sort(arr, arr + 8);
    v1(arr, 0, 8);
    print(arr, 0, 8);
    return 0;
    int *arr_s = getRandData(SMALL_DATA_N);
    int *arr_b = getRandData(BIG_DATA_N);
    TEST(v0, arr_s, SMALL_DATA_N);
    TEST(v0, arr_b, BIG_DATA_N);
    TEST(v1, arr_b, BIG_DATA_N);
    TEST(v2, arr_b, BIG_DATA_N);
    TEST(v3, arr_b, BIG_DATA_N);
    TEST(v4, arr_b, BIG_DATA_N);
    return 0;
}