#include <iostream>
using namespace std;

// 一维数组实现单向静态链表（局限性：数组下标是data、数组值是next指针域）
int nodes[150];  // nodes[i]的i就是结点的值、而nodes[i]的值就是下一个结点
int n, m;

int main() {
    cin >> n >> m;

    // 建立链表
    for (int i = 1; i <= n - 1; i++) {
        nodes[i] = i + 1;  // nodes[i]的值就是下一个结点，更新指针域
    }
    nodes[n] = 1;  // 建立循环链表, 尾指向头

    // 处理
    int cur = 1, prev;
    while (n > 1) {
        for (int i = 1; i < m; i++) {
            prev = cur;
            cur = nodes[cur];
        }
        n--;
        cout << cur << " ";
        nodes[prev] = nodes[cur];  // 跳过cur,即删除cur
        cur = nodes[prev];
    }
    cout << cur;
    return 0;
}