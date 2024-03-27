#include <iostream>
// using namespace std; // 不注释会导致next报重定义。next是保留字

int data[10];
int next[10];

// 在idx结点后面添加node结点，node结点值为val
void add(int idx, int node, int val) {
    next[node] = next[idx]; // 插入两步
    next[idx] = node;
    data[node] = val;
}

int main() {
    int head = 3; // 比如头结点在地址3上
    data[3] = 0;

    add(3, 5, 1);
    add(5, 2, 2);
    add(2, 7, 3);
    add(7, 9, 4);
    add(5, 1, 123); // 中间插入测试

    int p = head;
    // 遍历
    while (p != 0) {
        printf("%d->", data[p]);
        p = next[p];
    } printf("\n");

    return 0;
}