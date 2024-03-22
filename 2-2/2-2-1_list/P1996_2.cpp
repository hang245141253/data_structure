#include <iostream>
using namespace std;

const int N = 105;

// 结构体数组实现单向静态链表
struct node {
    int data, next;
} nodes[N];

int n, m;

int main() {
    cin >> n >> m;

    // 建立链表
    nodes[0].next = 1;  // 0号位置是头结点, 指向位置1表示可用位置
    for (int i = 1; i <= n; i++) {
        nodes[i].data = i;
        nodes[i].next = i + 1;
    }
    nodes[n].next = 1; // 建立循环链表

    // 处理
    int cur = 1, prev;
    while (n > 1) {
        for (int i = 1; i < m; i++) {
            prev = cur;
            cur = nodes[cur].next;
        }
        cout << nodes[cur].data << " ";
        nodes[prev].next = nodes[cur].next;
        // 跳过这个点就相当于是删除，静态链表不需要释放
        cur = nodes[prev].next;
        n--;
    }
    cout << nodes[cur].data;
    return 0;
}