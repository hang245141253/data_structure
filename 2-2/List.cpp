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

// 结点，只有后继，是单向链表
struct ListNode {
    ElemType data;
    struct ListNode* next;
};

// 链表
struct List {
    struct ListNode* head;
    struct ListNode* tail;
    size_t size;
};

// 初始化链表
void initList(List& list) {
    list.head = list.tail = NULL;
    list.size = 0;
}

// 创建节点
ListNode* createNode(int value) {
    ListNode* newNode = new ListNode;
    if (newNode == nullptr) {
        // 处理内存分配失败的情况
        cerr << "Memory allocation failed" << endl;
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

    if (list.tail == nullptr) {  // 如果链表为空，那么这个结点既是头部也是尾部
        list.head = list.tail = newNode;
    } else {
        list.tail->next = newNode;
        list.tail = newNode;
    }

    list.size++;
}

// 插入元素到指定位置
/*
size_t 是 C/C++ 中的一种无符号整数类型，
通常用于表示对象的大小或容器的大小。
它是根据系统架构的不同而有所变化，但它总是足够大以容纳系统中最大可能的对象大小。
*/
void insert(List& list, size_t position, int value) {
    if (position > list.size) {
        cerr << "Invalid position for insertion" << endl;
        return;
    }

    if (position == 0) {
        pushFront(list, value);
    } else if (position == list.size) {
        pushBack(list, value);
    } else {
        ListNode* newNode = createNode(value);
        ListNode* current = list.head;
        
        // 遍历n - 1次, 到要插入位置前一个结点处
        for (size_t i = 1; i < position; ++i) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        list.size++;
    }
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

        // 单项链表只能从头找删除的前一个位置
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

// 删除链表中特定位置的节点
void erase(List& list, size_t position) {
    if (position >= list.size) {
        cerr << "Invalid position for erasing" << endl;
        return;
    }

    if (position == 0) {
        popFront(list);
    } else if (position == list.size - 1) {
        popBack(list);
    } else {
        ListNode* current = list.head;  // 头结点的位置是0
        ListNode* prev = nullptr;       // 当前位置的前一个结点

        // 遍历n次, 到要删除位置结点处
        for (size_t i = 0; i < position; ++i) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        delete current;

        list.size--;
    }
}

// 打印链表元素
void printList(const List& list) {
    const ListNode* current = list.head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
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
        // 如果用popBack效率会变慢
    }
}

// 析构函数，释放链表内存
void destroyList(List& list) {
    clearList(list);
}

int main() {
    List myList;
    initList(myList);

    pushBack(myList, 1);
    pushBack(myList, 2);
    pushFront(myList, 0);

    insert(myList, 2, 5);    // 在位置2插入元素5
    insert(myList, 2, 6);    // 在位置2插入元素5
    insert(myList, 2, 7);    // 在位置2插入元素5
    insert(myList, 999, 8);  // 在位置999插入元素5

    cout << "List size: " << getSize(myList) << endl;
    printList(myList);

    popFront(myList);
    popBack(myList);
    erase(myList, 3);    // 删除位置3的元素
    erase(myList, 999);  // 删除位置999的元素

    cout << "List size: " << getSize(myList) << endl;
    printList(myList);

    clearList(myList);

    cout << "List size: " << getSize(myList) << endl;

    destroyList(myList);

    return 0;
}
