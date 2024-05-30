#include <iostream>
using namespace std;

#define MAX_N 1000
int data[MAX_N + 5], cnt = 0; // cnt记录当前堆中元素数量

int top() {
    return data[0];
}

int size() {
    return cnt;
}

// 新元素插入到数组末尾，然后向上调整
void push(int x) {
    data[cnt++] = x; // 把新加入元素放到数组末尾
    int idx = cnt - 1;   // 获取新元素的下标，准备做向上调整
    /*
        我们要获取新元素的父节点下标，需要反推：
        因为我们的数组下标是从0开始的，
        父节点为i的话两，个孩子下标是2i + 1，2i + 2
        所以反推父节点应该是：(子节点 - 1) / 2
    */

    // 如果idx不在树根，且idx的父节点的值比idx的值小
    while (idx && data[(idx - 1) / 2] < data[idx]) { 
        swap(data[(idx - 1) / 2], data[idx]); // 交换，成为新的爸爸
        idx = (idx - 1) / 2;                  // 更新idx 
    }
    return;
}

// 让数组最后的元素成为树根，然后向下调整
void pop() {
    if (size() == 0) return;   // 为空不能pop
    data[0] = data[cnt - 1];
    cnt--;
    int idx = 0, n = cnt - 1;  // 指定新元素的下标idx，准备做向下调整; n表示最大的子节点下标
    while (idx * 2 + 1 <= n) { // 左孩子的idx <= 最大子节下标时 （右孩子不一定存在，有可能没有右孩子但是有左孩子）

    }
}



int main() {
    
    return 0;
}