#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node *cur, *prev; 

int main() {
    int n, m;
    cin >> n >> m;

    // 建立链表
    Node* head = new Node;
    head->data = 1, head->next = nullptr;

    cur = head;
    for (int i = 2; i < n; i++) {
        Node* p = new Node;
        p->data = i, p->next = nullptr;
        cur->next = p;
        cur = cur->next; // 或者 cur = p
    }
    cur->next = head; // 建立循环链表   
    // debug遍历
    for (Node* i = head; i != nullptr; i = i->next) {
        cout << i->data << " ";
     }

    cur = head;

    return 0;
}