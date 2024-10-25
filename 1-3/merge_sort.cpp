#include <iostream>
using namespace std;

// 两大阶段：分治 归并
// 分析完流程后，再分析如何计算时间复杂度
// 代码演示



// l,r是左闭右开的
void merge_sort(int *arr, int l, int r) {
    // 递归，先思考边界条件
    if (r - l <= 1) return;
    int mid = (l + r) / 2;  // 假设一个只有两个元素的数组 则mid=1 l=0 r=2
    merge_sort(arr, l, mid);
    merge_sort(arr, mid, r);  // 分治处理

    // 归并处理
    int p1 = l, p2 = mid, k = 0; // k是temp数组的指针
    int *temp = (int *)malloc(sizeof(int) * (r - l)); // 大小与当前待排序区间的数组相同
    while (p1 < mid || p2 < r) { // 当两个数组其中之一还有元素没排好的时候
        // 思考：什么情况下把第一个数组中的元素放进temp数组中
        // 两个情况：1.第二个数组没有元素了 2.第一个数组不为空且p1的元素<p2的元素
        if (p2 == r || (p1 < mid && arr[p1] < arr[p2])) {
            temp[k++] = arr[p1++];
        } else {
            temp[k++] = arr[p2++];
        }
    }
    for (int i = l; i < r; i++) arr[i] = temp[i - l]; // 复制回原数组
    free(temp);
}

int main() {

    return 0;
}