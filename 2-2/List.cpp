#include <iostream>
#include <list>
using namespace std;

typedef int ElemType;  // 数据元素类型约定为ElemType, 由用户在使用该数据类型时自行定义

/*
为什么要有链表的存在?（相比较顺序表的优势而言）
    线性存储结构在进行中间插入和删除操作时需移动大量元素，浪费资源.
    所以考虑链式存储的线性表：即 链表


*/

/****************************** 结构定义 ************************************/

// 链表结点结构体
struct ListNode {
    ElemType data;
    struct ListNode* next;
};

// 链表结构体
struct List {
    struct ListNode* head;
    struct ListNode* tail;
    size_t size;
};

// 初始化链表
void initializeList(List& list) {
    list.head = list.tail = NULL;
    list.size = 0;
}

// 创建节点
ListNode* createNode(int value) {
    ListNode* newNode = new ListNode;
    if (newNode == nullptr) {
        // 处理内存分配失败的情况
        std::cerr << "Memory allocation failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = nullptr;

    return newNode;
}

// 在链表头部插入元素
void pushFront(List& list, int value) {
    ListNode* newNode = createNode(value);

    if (list.head == nullptr) {
        list.head = list.tail = newNode;
    } else {
        newNode->next = list.head;
        list.head = newNode;
    }

    list.size++;
}

// 在链表尾部插入元素
void pushBack(List& list, int value) {
    ListNode* newNode = createNode(value);

    if (list.tail == nullptr) {
        list.head = list.tail = newNode;
    } else {
        list.tail->next = newNode;
        list.tail = newNode;
    }

    list.size++;
}

// 删除链表头部元素
void popFront(List& list) {
    if (list.head != nullptr) {
        ListNode* temp = list.head;
        list.head = list.head->next;
        delete temp;

        if (list.head == nullptr) {
            list.tail = nullptr;
        }

        list.size--;
    }
}

// 删除链表尾部元素
void popBack(List& list) {
    if (list.head != nullptr) {
        ListNode* temp = list.head;
        ListNode* prev = nullptr;

        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }

        delete temp;

        if (prev == nullptr) {
            list.head = list.tail = nullptr;
        } else {
            prev->next = nullptr;
            list.tail = prev;
        }

        list.size--;
    }
}

// 打印链表元素
void printList(const List& list) {
    const ListNode* current = list.head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// 判断链表是否为空
bool isEmpty(const List& list) {
    return list.size == 0;
}

// 获取链表大小
size_t getSize(const List& list) {
    return list.size;
}

// 清空链表
void clearList(List& list) {
    while (list.head != nullptr) {
        popFront(list);
    }
}

// 析构函数，释放链表内存
void destroyList(List& list) {
    clearList(list);
}

int main() {
    List myList;
    initializeList(myList);

    pushBack(myList, 1);
    pushBack(myList, 2);
    pushFront(myList, 0);

    std::cout << "List size: " << getSize(myList) << std::endl;
    printList(myList);

    popFront(myList);
    popBack(myList);

    std::cout << "List size: " << getSize(myList) << std::endl;
    printList(myList);

    clearList(myList);

    std::cout << "List size: " << getSize(myList) << std::endl;

    destroyList(myList);

    return 0;
}
