#include <iostream>
using namespace std;

struct Node {
    // 构造函数
    Node(int d) : data(d), next(nullptr) {}
    int data;
    Node* next;
};

void reverse(Node *p) {
    if (p == nullptr) return;
    reverse(p->next);
    printf("%d->", p->data);
    return;
}

// 扩展反转链表:反转前n个结点
Node* reverse(Node *head, int n) {
    if (n == 1) return head;
    Node *tail = head->next, *new_head = reverse(head->next, n - 1); 
    head->next = tail->next; // 这里不能写成head->next = nullptr,因为不是尾插
    tail->next = head;
    return new_head;
}

int main() {
    Node* head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // 通过递归回溯反转
    reverse(head), printf("\n");

    // 反转前n个
    head = reverse(head, 3);

    // 遍历
    Node* p = head;
    while (p != nullptr) {
        printf("%d->", p->data);
        p = p->next;
    } printf("\n");

    

    return 0;
}