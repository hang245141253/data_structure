#include <iostream>
using namespace std;

#define N 100000

int head;       // 头结点(下标)
int e[N + 5];   // 结点i的值
int ne[N + 5];  // 结点i的next指针
int idx;        // 当前链表用到了哪个位置

// 初始化
void init() {
    head = -1;
    idx = 0;
}

// 将元素x插入到头结点(算法题80%的情况是把元素插入到头结点后面)
void add_to_head(int x) {
    e[idx] = x; // 在第idx位置上插入元素x
    ne[idx] = head; // 被插元素先指头结点的位置
    head = idx; // 更新头结点位置
    idx++; // 插入了一个元素
}

int main() {
    return 0;
}