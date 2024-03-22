#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int n, m;
Node* head;

void print() {
    Node* cur = head;
    // debug遍历
    for (int i = 0; i < n; i++) {
        cout << cur->data << " ";
        cur = cur->next;
    }
}

int main() {
    cin >> n >> m;

    // 建立链表
    head = new Node;
    head->data = 1, head->next = nullptr;

    Node* cur = head;
    for (int i = 2; i <= n; i++) {
        Node* p = new Node;
        p->data = i, p->next = nullptr;
        cur->next = p;
        cur = cur->next;  // 或者 cur = p
    }
    cur->next = head;  // 建立循环链表

    // print(); // 测试输入

    // 处理
    Node* prev;  // 删除结点用
    cur = head;

    while (n > 1) {  // 循环n - 1次
        for (int i = 1; i < m; i++) {
            prev = cur;
            cur = cur->next;
        }
        cout << cur->data << " ";
        prev->next = cur->next;
        delete cur;
        cur = prev->next;
        n--;
    }
    cout << cur->data;
    delete cur;
    return 0;
}