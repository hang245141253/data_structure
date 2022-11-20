#include <iostream>
using namespace std;

struct Node {
    Node(int data) : data(data), next(NULL) {}
    int data;
    Node *next;
} ;


int main() {
    Node *head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    Node *p = head;
    while (p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");
    

    return 0;
}