#include <iostream>
using namespace std;

typedef int ElemType; 

struct LNode {
    ElemType data;
    struct LNode* next;
};

struct List {
    struct LNode* head;
    struct LNode* tail;
    size_t size;
};

void init(List &L) {
    L.head = L.tail = NULL;
    L.size = 0;
}

LNode* createNode (ElemType val) {
    LNode* newNode = new LNode;
    if (newNode == NULL)
        return NULL; 
    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

void pushFront(List& L, int val) {
    LNode* newNode = createNode(val);
    if (newNode == NULL)
        return ;
    if (L.head == NULL) {
        L.head = L.tail = newNode;
    } else {
        newNode->next = L.head;
        L.head = newNode;
    }
    L.size++;
}

void pushBack(List& L, int val) {
    LNode* newNode = createNode(val);
    if (newNode == NULL)
        return ;
    if (L.tail == NULL) {
        L.head = L.tail = newNode;
    } else {
        L.tail->next = newNode;
        L.tail = newNode;
    }
    L.size++;
}

void insert(List& L, size_t idx, int val) {
    if (idx > L.size)
        return ;
    if (idx == 0) 
        pushFront(L, val);
    else if (idx == L.size)
        pushBack(L, val);
    else {
        LNode* newNode = createNode(val);
        LNode* cur = L.head;

        for (int i = 1; i < idx; i++) {
            cur = cur->next;
        }

        newNode->next = cur->next;
        cur->next = newNode;
        L.size++;
    }
}


// 删除链表头部元素
void popFront(List& list) {
    if (list.head != NULL) {
        LNode* temp = list.head;
        list.head = list.head->next;
        delete temp;

        if (list.head == NULL) {
            list.tail = NULL;
        }

        list.size--;
    }
}

// 删除链表尾部元素
void popBack(List& list) {
    if (list.head != NULL) {
        LNode* temp = list.head;
        LNode* prev = NULL;

        // 单项链表只能从头找删除的前一个位置
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        delete temp;

        if (prev == NULL) {
            list.head = list.tail = NULL;
        } else {
            prev->next = NULL;
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
        LNode* current = list.head;  // 头结点的位置是0
        LNode* prev = NULL;       // 当前位置的前一个结点

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

int findElemPos(List& L, int val) {
    LNode* cur = L.head;
    int position = 0;

    while (cur != NULL) {
        if (cur->data == val) {
            return position;  // 返回找到的节点的位置
        }
        cur = cur->next;
        position++;
    }

    return -1;  // 未找到时返回-1
}

int findElemNext(List& L, int val) {
    LNode* cur = L.head;

    while (cur != NULL) {
        if (cur->data == val) {
            break;
        }
        cur = cur->next;
    }

    return (cur->next == NULL ? 0 : cur->next->data); 
}

void printList(List& L) {
    LNode* cur = L.head;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    List L;
    init(L);
    pushBack(L, 1);

    int q;
    cin >> q;
    while (q--) {
        int op, x, y;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            insert(L, findElemPos(L, x) + 1, y);
        } else if (op == 2) {
            cin >> x;
            cout << findElemNext(L, x) << endl;
        } else if (op == 3) {
            cin >> x;
            erase(L, findElemPos(L, x) + 1);
        }
    }

    // // 将元素 y 插入到 x 后面, 所以+1
    // insert(L, findElemPos(L, 1) + 1, 99);
    // insert(L, findElemPos(L, 99) + 1, 50);
    // insert(L, findElemPos(L, 99) + 1, 75);
    // cout << findElemNext(L, 99) << endl;
    // erase(L, findElemPos(L, 75) + 1);
    // cout << findElemNext(L, 1) << endl;

    // printList(L);

    return 0;
}