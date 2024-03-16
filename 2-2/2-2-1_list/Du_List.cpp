#include <iostream>  // 包含输入输出流库

using namespace std;  // 使用标准命名空间

// 定义双向链表节点结构体
struct Node {    // 定义节点结构体
    int data;    // 数据域
    Node *prev;  // 指向前一个节点的指针
    Node *next;  // 指向后一个节点的指针
};

// 定义双向链表结构体
struct List {     // 定义链表结构体
    Node *head;   // 头节点指针
    Node *tail;   // 尾节点指针
    size_t size;  // 链表大小
};

// 初始化双向链表
void list_init(List &list) {  // 初始化链表函数
    list.head = nullptr;      // 头节点指针置空
    list.tail = nullptr;      // 尾节点指针置空
    list.size = 0;            // 链表大小为0
}

// 在链表末尾插入元素
void push_back(List &list, int data) {  // 在末尾插入元素函数
    Node *new_node = new Node;          // 创建新节点
    new_node->data = data;              // 设置新节点数据
    new_node->prev = list.tail;         // 新节点的前指针指向尾节点
    new_node->next = nullptr;           // 新节点的后指针置空

    if (list.tail != nullptr)        // 如果尾节点不为空
        list.tail->next = new_node;  // 尾节点的后指针指向新节点
    else
        list.head = new_node;  // 否则头节点指向新节点

    list.tail = new_node;  // 尾节点指向新节点
    list.size++;           // 链表大小加一
}

// 删除链表末尾的元素
void pop_back(List &list) {    // 删除末尾元素函数
    if (list.tail == nullptr)  // 如果尾节点为空，直接返回
        return;

    Node *temp = list.tail;         // 临时节点指向尾节点
    list.tail = temp->prev;         // 尾节点指向前一个节点
    if (list.tail != nullptr)       // 如果尾节点不为空
        list.tail->next = nullptr;  // 前一个节点的后指针置空
    else
        list.head = nullptr;  // 否则头节点置空

    delete temp;  // 释放临时节点内存
    list.size--;  // 链表大小减一
}

// 获取链表大小
size_t size(const List &list) {  // 获取链表大小函数
    return list.size;            // 返回链表大小
}

// 在指定位置插入元素
void insert(List &list, size_t index, int data) {  // 在指定位置插入元素函数
    if (index > list.size)                         // 如果插入位置大于链表大小，直接返回
        return;

    Node *cur = list.head;              // 当前节点指向头节点
    for (size_t i = 0; i < index; i++)  // 遍历找到插入位置
        cur = cur->next;

    Node *new_node = new Node;   // 创建新节点
    new_node->data = data;       // 设置新节点数据
    new_node->prev = cur->prev;  // 新节点的前指针指向当前节点的前一个节点
    new_node->next = cur;        // 新节点的后指针指向当前节点

    if (cur->prev != nullptr)        // 如果当前节点的前指针不为空
        cur->prev->next = new_node;  // 前一个节点的后指针指向新节点
    else
        list.head = new_node;  // 否则头节点指向新节点

    cur->prev = new_node;  // 当前节点的前指针指向新节点
    list.size++;           // 链表大小加一
}

// 删除指定位置的元素
void erase(List &list, size_t index) {  // 删除指定位置元素函数
    if (index >= list.size)             // 如果删除位置大于等于链表大小，直接返回
        return;

    Node *cur = list.head;              // 当前节点指向头节点
    for (size_t i = 0; i < index; i++)  // 遍历找到删除位置
        cur = cur->next;

    if (cur->prev != nullptr)         // 如果当前节点的前指针不为空
        cur->prev->next = cur->next;  // 前一个节点的后指针指向当前节点的后一个节点
    else
        list.head = cur->next;  // 否则头节点指向当前节点的后一个节点

    if (cur->next != nullptr)         // 如果当前节点的后指针不为空
        cur->next->prev = cur->prev;  // 后一个节点的前指针指向当前节点的前一个节点
    else
        list.tail = cur->prev;  // 否则尾节点指向当前节点的前一个节点

    delete cur;   // 释放当前节点内存
    list.size--;  // 链表大小减一
}

// 获取指定位置的元素值
int get(const List &list, size_t index) {  // 获取指定位置元素值函数
    if (index >= list.size)                // 如果位置大于等于链表大小，返回-1
        return -1;                         // 假设数据不会为负值

    Node *cur = list.head;              // 当前节点指向头节点
    for (size_t i = 0; i < index; i++)  // 遍历找到指定位置
        cur = cur->next;

    return cur->data;  // 返回当前节点的数据
}

int main() {          // 主函数
    List list;        // 创建链表对象
    list_init(list);  // 初始化链表

    // 在链表末尾插入元素
    push_back(list, 10);
    push_back(list, 20);
    push_back(list, 30);

    // 输出链表元素
    for (size_t i = 0; i < size(list); i++)  // 遍历输出链表元素
        cout << get(list, i) << " ";         // 输出当前位置元素
    cout << endl;                            // 换行

    // 删除链表末尾的元素
    pop_back(list);

    // 在指定位置插入元素
    insert(list, 1, 25);

    // 删除指定位置的元素
    erase(list, 0);

    // 输出链表元素
    for (size_t i = 0; i < size(list); i++)  // 遍历输出链表元素
        cout << get(list, i) << " ";         // 输出当前位置元素
    cout << endl;                            // 换行

    return 0;  // 返回0表示程序正常结束
}