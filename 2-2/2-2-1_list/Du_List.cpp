#include <iostream>
using namespace std;

// 定义双向链表节点结构体
struct Node {
    int data;
    Node *prev;
    Node *next;
};

// 定义双向链表结构体
struct List {
    Node *head;
    Node *tail;
    size_t size;
};

// 初始化双向链表
void list_init(List &list) {
    list.head = nullptr;
    list.tail = nullptr;
    list.size = 0;
}

// 在链表末尾插入元素
void push_back(List &list, int data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->prev = list.tail;
    new_node->next = nullptr;

    if (list.tail != nullptr)
        list.tail->next = new_node;
    else
        list.head = new_node;

    list.tail = new_node;
    list.size++;
}

// 删除链表末尾的元素
void pop_back(List &list) {
    if (list.tail == nullptr)
        return;

    Node *temp = list.tail;
    list.tail = temp->prev;
    if (list.tail != nullptr)
        list.tail->next = nullptr;
    else
        list.head = nullptr;

    delete temp;
    list.size--;
}

// 获取链表大小
size_t size(const List &list) {
    return list.size;
}

// 在指定位置插入元素
void insert(List &list, size_t index, int data) {
    if (index > list.size)
        return;

    Node *cur = list.head;
    for (size_t i = 0; i < index; i++)
        cur = cur->next;

    Node *new_node = new Node;
    new_node->data = data;
    new_node->prev = cur->prev;
    new_node->next = cur;

    if (cur->prev != nullptr)
        cur->prev->next = new_node;
    else
        list.head = new_node;

    cur->prev = new_node;
    list.size++;
}

// 删除指定位置的元素
void erase(List &list, size_t index) {
    if (index >= list.size)
        return;

    Node *cur = list.head;
    for (size_t i = 0; i < index; i++)
        cur = cur->next;

    if (cur->prev != nullptr)
        cur->prev->next = cur->next;
    else
        list.head = cur->next;

    if (cur->next != nullptr)
        cur->next->prev = cur->prev;
    else
        list.tail = cur->prev;

    delete cur;
    list.size--;
}

// 获取指定位置的元素值
int get(const List &list, size_t index) {
    if (index >= list.size)
        return -1; // 这里假设数据不会为负值

    Node *cur = list.head;
    for (size_t i = 0; i < index; i++)
        cur = cur->next;

    return cur->data;
}

int main() {
    List list;
    list_init(list);

    // 在链表末尾插入元素
    push_back(list, 10);
    push_back(list, 20);
    push_back(list, 30);

    // 输出链表元素
    for (size_t i = 0; i < size(list); i++)
        cout << get(list, i) << " ";
    cout << endl;

    // 删除链表末尾的元素
    pop_back(list);

    // 在指定位置插入元素
    insert(list, 1, 25);

    // 删除指定位置的元素
    erase(list, 0);

    // 输出链表元素
    for (size_t i = 0; i < size(list); i++)
        cout << get(list, i) << " ";
    cout << endl;

    return 0;
}
