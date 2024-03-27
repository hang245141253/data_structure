#include <iostream>
using namespace std;

struct Node {
    // 构造函数
    Node(int d) : data(d), next(nullptr) {}
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // 遍历
    Node* p = head;
    while (p != nullptr) {
        printf("%d->", p->data);
        p = p->next;
    } printf("\n");

    return 0;
}