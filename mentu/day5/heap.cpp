#include <iostream>
using namespace std;

#define MAX_N 1000
int arr[MAX_N + 5], cnt = 0; // cnt记录当前堆中元素数量


// 获取堆顶元素值
int top() {
    return arr[0];
}

// 获取堆的大小
int size() {
    return cnt;
}


// 如果想让代码更漂亮的话，单独封装向上调整、向下调整
void shift_up(int idx) {
    while (idx && arr[(idx - 1) / 2] < arr[idx]) { 
        swap(arr[(idx - 1) / 2], arr[idx]); // 交换，成为新的爸爸
        idx = (idx - 1) / 2;                  // 更新idx 
    }
}

void shift_down(int idx) {
    int n = cnt - 1;
    while (idx * 2 + 1 <= n) { // 有孩子则循环 （有孩子：一定有左孩子idx * 2 + 1，右孩子idx * 2 + 2不一定有）
        int tmp = idx; // tmp指向三元组中最大值的下标
        if (arr[tmp] < arr[idx * 2 + 1]) tmp = idx * 2 + 1; // 如果根比左子树小，tmp指向左子树
        if (idx * 2 + 2 <= n && arr[tmp] < arr[idx * 2 + 2]) tmp = idx * 2 + 2;
        
        if (tmp == idx) break; // 如果没发生调整，说明已经调整完毕

        // 如果发生了调整
        swap(arr[tmp], arr[idx]); // 交换元素
        idx = tmp;                  // 更新idx
    }
}

// 新元素插入到数组末尾，然后向上调整
void push(int x) {
    arr[cnt++] = x; // 把新加入元素放到数组末尾
    shift_up(cnt - 1);

    // int idx = cnt - 1;   // 获取新元素的下标，准备做向上调整
    // /*
    //     我们要获取新元素的父节点下标，需要反推：
    //     因为我们的数组下标是从0开始的，
    //     父节点为i的话两，个孩子下标是2i + 1，2i + 2
    //     所以反推父节点应该是：(子节点 - 1) / 2
    // */

    // // 如果idx不在树根，且idx的父节点的值比idx的值小
    // while (idx && arr[(idx - 1) / 2] < arr[idx]) { 
    //     swap(arr[(idx - 1) / 2], arr[idx]); // 交换，成为新的爸爸
    //     idx = (idx - 1) / 2;                  // 更新idx 
    // }
    return;
}

// 让数组最后的元素成为树根，然后向下调整
void pop() {
    if (size() == 0) return;   // 为空不能pop
    swap(arr[0], arr[cnt - 1]);
    cnt--;
    shift_down(0);
    // int idx = 0, n = cnt - 1;  // 指定新元素的下标idx，准备做向下调整; n表示最大的子节点下标
    // while (idx * 2 + 1 <= n) { // 有孩子则循环 （有孩子：一定有左孩子idx * 2 + 1，右孩子idx * 2 + 2不一定有）
    //     int tmp = idx; // tmp指向三元组中最大值的下标
    //     if (arr[tmp] < arr[idx * 2 + 1]) tmp = idx * 2 + 1; // 如果根比左子树小，tmp指向左子树
    //     if (idx * 2 + 2 <= n && arr[tmp] < arr[idx * 2 + 2]) tmp = idx * 2 + 2;
        
    //     if (tmp == idx) break; // 如果没发生调整，说明已经调整完毕

    //     // 如果发生了调整
    //     swap(arr[tmp], arr[idx]); // 交换元素
    //     idx = tmp;                  // 更新idx
    // }
}

void output(int n) {
    printf("heap : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
}

int main() {
    int op, val;
    int max_n = 0;
    while (cin >> op) {
        switch (op) {
        case 0:
            cin >> val; 
            max_n++;
            printf("Push %d to heap\n", val);
            push(val);
            break;
        case 1:
            printf("Pop %d from heap\n", top());
            pop();
            break; 
        case 2:
            output(max_n); // 查看堆排序任务的结果
            break;
        }
        output(cnt);
    }    
    return 0;
}

