#include <iostream>
using namespace std;

const int N = 105;

// 结构体数组实现双向静态链表
struct node {
    int data, next, prev;
} nodes[N];

int n, m;

int main() {
    cin >> n >> m;

    // 建立链表
    nodes[0].next = 1; // 0号位置是头结点, 指向位置1表示可用位置
    for (int i = 1; i <= n; i++) {
        nodes[i].data = i;
        nodes[i].prev = i - 1;
        nodes[i].next = i + 1;
    }
    nodes[n].next = 1;  // 建立循环链表，尾指向头
    nodes[1].prev = n;  // 头指向尾

    // 处理
    int cur = 1; // 双向链表不需要定义prev了
    while (n > 1) {
        for (int i = 1; i < m; i++) {
            cur = nodes[cur].next;
        }
        cout << nodes[cur].data << " ";
        
        // 双向链表的删除
        int prev = nodes[cur].prev, next = nodes[cur].next;
        nodes[prev].next = nodes[cur].next;
        nodes[next].prev = nodes[cur].prev;
        cur = next;
        n--;
    }
    cout << nodes[cur].data;

    return 0;
}