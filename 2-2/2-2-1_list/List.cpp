#include <iostream>
using namespace std;

typedef int ElemType;  // 数据元素类型

// 单链表节点定义
struct ListNode {
    ElemType val;      // 节点存储的值
    ListNode* next;    // 指向下一个节点的指针
    // 构造函数，初始化节点值为x，next为nullptr
    ListNode(ElemType x) : val(x), next(nullptr) {}
};

// 在链表头插入节点
void push_front(ListNode*& head, ElemType value) {
    ListNode* new_node = new ListNode(value);  // 创建新节点
    new_node->next = head;  // 新节点的next指向当前头节点
    head = new_node;  // 更新头节点为新节点
}

// 在链表尾插入节点
void push_back(ListNode*& head, ElemType value) {
    ListNode* new_node = new ListNode(value);  // 创建新节点
    if (!head) {  // 如果链表为空，直接将新节点作为头节点
        head = new_node;
    } else {
        ListNode* cur = head;
        while (cur->next) {  // 遍历链表到达尾部
            cur = cur->next;
        }
        cur->next = new_node;  // 将新节点连接到链表尾部
    }
}

// 在指定位置插入节点
void insert(ListNode*& head, size_t index, ElemType value) {
    if (index == 0) {
        push_front(head, value);  // 如果插入位置是0，调用push_front插入
        return;
    }

    ListNode* cur = head;
    for (size_t i = 1; i < index; ++i) {  // 遍历找到目标位置的前一个节点
        if (!cur) {  // 如果当前位置超出了链表的长度
            cout << "Index out of bounds!" << endl;
            return;
        }
        cur = cur->next;
    }

    ListNode* new_node = new ListNode(value);  // 创建新节点
    new_node->next = cur->next;  // 新节点的next指向原来节点的next
    cur->next = new_node;  // 将前一个节点的next指向新节点
}

// 删除链表头节点
void pop_front(ListNode*& head) {
    if (!head) {  // 如果链表为空
        cout << "List is empty!" << endl;
        return;
    }
    ListNode* temp = head;  // 暂存头节点
    head = head->next;  // 更新头节点为下一个节点
    delete temp;  // 删除原头节点
}

// 删除链表尾节点
void pop_back(ListNode*& head) {
    if (!head) {  // 如果链表为空
        cout << "List is empty!" << endl;
        return;
    }
    if (!head->next) {  // 如果链表只有一个节点
        delete head;  // 删除头节点
        head = nullptr;  // 头节点变为空
        return;
    }

    ListNode* cur = head;
    while (cur->next->next) {  // 遍历到倒数第二个节点
        cur = cur->next;
    }
    delete cur->next;  // 删除尾节点
    cur->next = nullptr;  // 更新倒数第二个节点的next为nullptr
}

// 删除指定位置的节点
void erase(ListNode*& head, size_t index) {
    if (index == 0) {
        pop_front(head);  // 如果是删除头节点，调用pop_front
        return;
    }

    ListNode* cur = head;
    for (size_t i = 1; i < index; ++i) {  // 遍历找到目标位置的前一个节点
        if (!cur) {
            cout << "Index out of bounds!" << endl;
            return;
        }
        cur = cur->next;
    }

    ListNode* temp = cur->next;  // 暂存目标节点
    if (temp) {
        cur->next = temp->next;  // 前一个节点的next指向目标节点的next
        delete temp;  // 删除目标节点
    } else {
        cout << "Index out of bounds!" << endl;
    }
}

// 修改指定位置的节点值
void set(ListNode* &head, size_t index, ElemType value) {
    ListNode* cur = head;
    for (size_t i = 0; i < index; ++i) {  // 遍历找到目标位置的节点
        if (!cur) {
            cout << "Index out of bounds!" << endl;
            return;
        }
        cur = cur->next;
    }
    cur->val = value;  // 修改节点值
}

// 获取链表头节点的值
ElemType front(ListNode* head) {
    if (!head) {  // 如果链表为空
        cout << "List is empty!" << endl;
        return ElemType();  // 返回默认值0
    }
    return head->val;  // 返回头节点的值
}

// 获取链表尾节点的值
ElemType back(ListNode* head) {
    if (!head) {  // 如果链表为空
        cout << "List is empty!" << endl;
        return ElemType();  // 返回默认值0
    }
    ListNode* cur = head;
    while (cur->next) {  // 遍历到最后一个节点
        cur = cur->next;
    }
    return cur->val;  // 返回尾节点的值
}

// 获取指定位置的节点值
ElemType at(ListNode* head, size_t index) {
    ListNode* cur = head;
    for (size_t i = 0; i < index; ++i) {  // 遍历找到目标位置的节点
        if (!cur) {
            cout << "Index out of bounds!" << endl;
            return ElemType();  // 返回默认值0
        }
        cur = cur->next;
    }
    return cur->val;  // 返回节点值
}

// 获取链表的大小
size_t size(ListNode* head) {
    size_t count = 0;
    ListNode* cur = head;
    while (cur) {  // 遍历链表并计数
        ++count;
        cur = cur->next;
    }
    return count;  // 返回链表大小
}

// 清空链表
void clear(ListNode*& head) {
    while (head) {
        pop_front(head);  // 依次删除链表头节点
    }
}

// 打印链表
void print(ListNode* head) {
    ListNode* cur = head;
    while (cur) {  // 遍历链表
        cout << cur->val << " -> ";  // 输出节点值
        cur = cur->next;
    }
    cout << "nullptr" << endl;  // 输出链表结束标志
}

// 测试代码
int main() {
    ListNode* head = nullptr;  // 初始化空链表

    push_back(head, 1);  // 在尾部插入1
    push_back(head, 2);  // 在尾部插入2
    push_back(head, 3);  // 在尾部插入3
    push_front(head, 0); // 在头部插入0
    insert(head, 2, 99); // 在索引2位置插入99
    print(head);  // 打印链表 0 -> 1 -> 99 -> 2 -> 3 -> nullptr

    pop_front(head);  // 删除头节点
    pop_back(head);   // 删除尾节点
    erase(head, 1);   // 删除索引1位置的节点
    print(head);  // 打印链表 1 -> 99 -> nullptr

    cout << "Front: " << front(head) << ", Back: " << back(head) << endl;  // 打印头尾节点值

    set(head, 1, 42);  // 修改索引1位置的节点值为42
    print(head);  // 打印链表 1 -> 42 -> nullptr

    clear(head);  // 清空链表
    cout << "List is empty: " << boolalpha << (head == nullptr) << endl;  // 判断链表是否为空

    return 0;
}
