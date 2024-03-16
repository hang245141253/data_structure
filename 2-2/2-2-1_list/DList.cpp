#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

struct DList {
    DNode* head;
    DNode* tail;
    size_t size;
};

void init(DList& l) {
    l.head = l.tail = nullptr;
    l.size = 0;
}

// 创建节点
DNode* createDNode(int value) {
    DNode* newDNode = new DNode;
    if (newDNode == nullptr) {
        // 处理内存分配失败的情况
        cerr << "Memory allocation failed" << endl;
        exit(EXIT_FAILURE);
    }

    newDNode->data = value;
    newDNode->next = nullptr;
    newDNode->prev = nullptr;

    return newDNode;
}

// 头插
void push_front(DList& l, int val) {
    DNode* newNode = createDNode(val);
    if (l.head == nullptr) {  // 头为空, 是第一个新结点
        l.head = l.tail = newNode;
    } else {
        // 属于前插
        newNode->next = l.head;
        l.head->prev = newNode;
        l.head = newNode;
    }
    l.size++;
}

// 尾插
void push_back(DList& l, int val) {
    DNode* newNode = createDNode(val);
    if (l.tail == nullptr) { // 尾为空, 是第一个新结点
        l.head = l.tail = newNode;
    } else {
        l.tail->next = newNode;
        newNode->prev = l.tail;
        l.tail = newNode;
    }
    l.size++;
}

// 插入
void insert(DList& l, size_t pos, int val) {
    if (pos > l.size) {
        cerr << "Invalid position" << endl;
        return;
    }

    if (pos == 0) {
        push_front(l, val);
    } else if (pos == l.size) {
        push_back(l, val);
    } else {
        DNode* cur = l.head;
        for (size_t i = 0; i < pos - 1; ++i) {
            cur = cur->next;
        }
        DNode* newNode = createDNode(val);
        
        // 对于在某点后插入
        newNode->prev = cur; // 1
        newNode->next = cur->next; // 3
        cur->next->prev = newNode; // 4
        cur->next = newNode; // 2不能在3 4之前发生， 必须在3 4之后
        
        l.size++;
    }
}

// 头删
void pop_front(DList& l) {
    if (l.head == nullptr) {
        cerr << "List is empty" << endl;
        return;
    }

    DNode* temp = l.head;
    l.head = l.head->next; // 往后走一步，前面的成为新的head
    if (l.head != nullptr) {
        l.head->prev = nullptr;
    } else {
        l.tail = nullptr; // 到尾了
    }
    delete temp;
    l.size--;
}

// 尾删
void pop_back(DList& l) {
    if (l.tail == nullptr) {
        cerr << "List is empty" << endl;
        return;
    }

    DNode* temp = l.tail;
    l.tail = l.tail->prev; // 往前走一步，前面的成为新的tail
    if (l.tail != nullptr) {
        l.tail->next = nullptr;
    } else {
        l.head = nullptr; // 到头了
    }
    delete temp;
    l.size--;
}

// 删除
void erase(DList& l, size_t pos) {
    if (pos >= l.size) {
        cerr << "Invalid position" << endl;
        return;
    }

    if (pos == 0) {
        pop_front(l);
    } else if (pos == l.size - 1) {
        pop_back(l);
    } else {
        DNode* cur = l.head;
        for (size_t i = 0; i < pos; ++i) {
            cur = cur->next;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        l.size--;
    }
}

// 输出打印
void printList(const DList& l) {
    cout << "List: ";
    DNode* cur = l.head;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    DList myList;
    init(myList);

    push_back(myList, 10);
    push_back(myList, 20);
    push_back(myList, 30);
    push_back(myList, 40);

    cout << "List size: " << myList.size << endl;

    push_front(myList, 0);
    insert(myList, 2, 999);

    printList(myList);

    erase(myList, 3);
    pop_front(myList);
    pop_back(myList);

    printList(myList);

    return 0;
}
