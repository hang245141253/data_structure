#include <iostream>
#include <cmath>
using namespace std;

/**
二分（折半）查找算法O(logN)：
作用：专门在有序数组中找到一个查找值的方法，无论有几个，只要有就行。

首先单调性：否则需要自己排序

需要3个指针，头指针、尾指针、mid指针 = (head + tail) / 2
*/

int binary_search(int *arr, int size, int val) {
    int head = 0, tail = size - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1; // (head + tail) ÷ 2
        if (arr[mid] == val) return mid;
        else if (arr[mid] < val) head = mid + 1;  // 不在左边 更新head
        else tail = mid - 1; // 不在右边 更新tail 
    }
    return -1; // 没找到
}

// 改递归
int binary_search2(int *arr, int head, int tail, int val) {
    if (head > tail) return -1; // 没找到
    int mid = (head + tail) >> 1;
    if (arr[mid] == val) return mid;

    if (arr[mid] < val) head = mid + 1;
    else tail = mid - 1;
    return binary_search2(arr, head, tail, val);
}


/** 二分查找的两个问题模型：
 * 需要考虑3个问题：
 * 1.mid指向0的时候如何处理
 * 2.mid指向1的时候如何处理
 * 3.头尾指针处于交界处时是否会出现bug
*/


// 0000011111 找第一个1(找数字第一次出现的位置，找>=x 的最小值，尽量往左找)
// 对于mid指向0的时：min = mid + 1 因为mid当前的位置是0，肯定不是要找的1
// 对于mid指向1的时：max = mid 因为当前的1有可能就是第一个1
// 对于交界处时：此时mid更新会把min更新到当前的max，无bug
int binary_search_F(int *arr, int size, int val) {
    int head = 0, tail = size - 1, mid;
    while (head < tail) {
        mid = (head + tail) >> 1; // (head + tail) ÷ 2
        if (arr[mid] >= val) tail = mid; // 不在右边 更新tail不减1,因为当前的tail可能是要找的
        else head = mid + 1;  // 不在左边 更新head 
    }
    return arr[head] == val ? head : -1;
}

// 1111122222 找最后一个1(找数字最后一次出现的位置，找<=x的最大值，尽量往右找)
// 对于mid指向1的时：min = mid 因为当前的1有可能就是最后一个1
// 对于mid指向2的时：max = mid - 1 因为mid当前的位置是2，肯定不是要找的1
// 对于交界处时：此时mid更新还是继续指向min，有bug，要+1
int binary_search_L(int *arr, int size, int val) {
    int head = 0, tail = size - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1; // (head + tail + 1) ÷ 2
        if (arr[mid] <= val) head = mid;  // 不在左边 更新head不减1,因为当前的head可能是要找的
        else tail = mid - 1; // 不在右边 更新tail 
    }
    return arr[head] == val ? head : -1;
}


/**
 * 连续问题、离散问题
 * 函数是连续 数组是离散
 * 数组是展开的函数 函数是压缩的数组
 * 
 */

// 二分答案实现sqrt
bool check(double x, double mid) {
    return mid * mid < x;
}

// max不+1.0会有bug 因为sqrt(0.1) = 0.316228 其中0.31>0.1答案并不在二分的区间
double my_sqrt(double x) {
    double min = 0, max = x + 1, mid;
    #define EPSL 1e-7 // 可以从1e-6开始 能观察出误差
    while (max - min > EPSL) {
        mid = (max + min) / 2.0;
        if (check(x, mid)) min = mid;
        else max = mid;
    }
    #undef EPSL
    return mid;
}


int main() {
    // double xx;
    // while (~scanf("%lf", &xx)) {
    //     printf("sqrt(%g) = %g\n", xx, sqrt(xx));
    //     printf("my_sqrt(%g) = %g\n", xx, my_sqrt(xx));
    // }
    // return 0;

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // arr[0] = rand() % 10;
    // for (int i = 1; i < n; i++) arr[i] = arr[i - 1] + rand() % 10;
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // } cout << endl;

    int x;
    while (cin >> x) {
        if (x == -1) break;
        // int ind = binary_search(arr, n, x);
        int ind = binary_search2(arr, 0, n, x);
        // int ind = binary_search_L(arr, n, x);
        if (ind == -1) {
            cout << "没找到\n";
        } else {
            printf("%d 在 arr[%d]\n", x, ind);
        }
    }
    delete arr;
    return 0;
}