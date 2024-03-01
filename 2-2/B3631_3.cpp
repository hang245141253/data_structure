#include <iostream>
#include <cstring>
using namespace std;
const int MAX_SIZE = 1000005;
const int N = 1e6 + 5;

// 记录值对应下标的位置，因为保证任何时间表中所有数字均不相同
int mmap[N]; // 数组里存的是值对应的下标

struct Node {
    int data;
    int next;
};

// head 表示头结点下标
// Node.data表示结点i的值
// Node.next表示结点i的next指针是多少
// idx表示当前用到了哪个位置
struct SList {
    Node nodes[MAX_SIZE];
    int head;
    int idx;
};

void init(SList& L) {
    L.head = -1;
    L.idx = 0;
}

// 
void pushFront(SList& L, int val) { 
    L.nodes[L.idx].data = val;
    L.nodes[L.idx].next = L.head;
    L.head = L.idx;
    L.idx++;
}

// 在x后面插入y
void insert(SList& L, int x, int y) {
    L.nodes[L.idx].data = y;

    int cur = L.head;
    while (cur != -1) {
        if (L.nodes[cur].data == x) break;
        cur = L.nodes[cur].next;
    }

    if (cur == -1)  return;

    L.nodes[L.idx].next = L.nodes[cur].next;
    L.nodes[cur].next = L.idx;

    // 优化
    mmap[y] = L.idx;

    L.idx++;
}

// 询问 x 后面的元素是什么。如果 x 是最后一个元素，则输出0
void find(SList& L, int x) {
    // int cur = L.head;
    // while (cur != -1) {
    //     if (L.nodes[cur].data == x) break;
    //     cur = L.nodes[cur].next;
    // }

    // if (cur == -1)  return;

    // cout << (L.nodes[cur].next == -1 ? 0 : L.nodes[L.nodes[cur].next].data) << endl;
    cout << (L.nodes[mmap[x]].next == -1 ? 0 : L.nodes[L.nodes[mmap[x]].next].data) << endl;
}

// 删除 x 后面的元素
void erase(SList& L, int x) {
    int cur = L.head;
    while (cur != -1) {
        if (L.nodes[L.nodes[cur].next].data == x) break;
        cur = L.nodes[cur].next;
    }

    if (cur == -1)  return;

    L.nodes[cur].next = L.nodes[L.nodes[cur].next].next;
}

void printSList(SList& L) {
    int cur = L.head;
    while (cur != -1) {
        cout << L.nodes[cur].data << " ";
        cur = L.nodes[cur].next;
    } cout << endl;
}

int main() {
    SList L;
    init(L);
    pushFront(L, 1);

    int q;
    cin >> q;
    while (q--) {
        int op, x, y;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            insert(L, x, y);
        } else if (op == 2) {
            cin >> x;
            find(L, x);
        } else if (op == 3) {
            cin >> x;
            erase(L, x);
        }
    }

    // insert(L, 1, 99);
    // insert(L, 99, 50);
    // insert(L, 99, 75);
    
    
    // find(L, 99);
    // erase(L, 75);
    // find(L, 1);

    // cout << "L.head = " << L.head << endl;
    // printSList(L); 

    return 0;   
}

// void printList(SList& L) {
//     int cur = L.head;
//     while (cur != -2) {
//         cout << L.nodes[cur].data << " ";
//         cur = L.nodes[cur].next;
//     }
//     cout << endl;
// }

// // 插入节点操作
// void insertNode(int x, int y) {
//     nodes[++tail].data = y; // 创建新节点，赋值为y
//     nodes[tail].next = nodes[x].next; // 新节点的next指向x节点的next
//     nodes[x].next = tail; // x节点的next指向新节点
// }

// // 查询节点操作
// int queryNode(int x) {
//     if (nodes[x].next == -2) {
//         return 0; // 如果x节点的next为-2，说明x是最后一个节点，返回0
//     } else {
//         return nodes[nodes[x].next].data; // 返回x节点的下一个节点的值
//     }
// }

// // 删除节点操作
// void deleteNode(int x) {
//     if (nodes[nodes[x].next].next == -2) {
//         nodes[x].next = -2; // 如果x的下一个节点是最后一个节点，直接将x的next指向-2
//     } else {
//         nodes[x].next = nodes[nodes[x].next].next; // 否则，将x的next指向下下个节点
//     }
// }

// int main() {
//     int q;
//     std::cin >> q; // 输入操作次数

//     nodes[head].data = 1; // 初始化头节点，值为1
//     nodes[head].next = -2; // 头节点的next指向-2，表示链表结束

//     while (q--) {
//         int op, x, y;
//         std::cin >> op >> x;
//         if (op == 1) {
//             std::cin >> y;
//             insertNode(x, y); // 插入节点操作
//         } else if (op == 2) {
//             std::cout << queryNode(x) << std::endl; // 查询节点操作
//         } else if (op == 3) {
//             deleteNode(x); // 删除节点操作
//         }
//     }

//     return 0;
// }


// #include <iostream>
// #include <cstring>
// using namespace std;

// const int MAX_SIZE = 1000005;  // 静态链表的最大大小

// struct Node {
//     int data;
//     int next;
// };

// struct SList {
//     Node nodes[MAX_SIZE];
//     int head;
//     int tail;
//     size_t size;
// };

// void init(SList& L) {
//     L.head = L.tail = -2;
//     L.size = 0;
//     memset(L.nodes, -1, sizeof(L.nodes));
// }

// int findElemPos(SList& L, int data) {
//     int cur = L.head;
//     int position = 0;

//     while (cur != -2) {
//         if (L.nodes[cur].data == data) {
//             return position;  // 返回找到的节点的位置
//         }
//         cur = L.nodes[cur].next;
//         position++;
//     }

//     return -2;  // 未找到时返回-2
// }

// int findElemNext(SList& L, int data) {
//     int cur = L.head;

//     while (cur != -2) {
//         if (L.nodes[cur].data == data) {
//             break;
//         }
//         cur = L.nodes[cur].next;
//     }

//     return (cur == -2 ? 0 : L.nodes[cur].next == -2 ? 0
//                                                     : L.nodes[L.nodes[cur].next].data);
// }

// void insert(SList& L, size_t idx, int data) {
//     if (idx > L.size)
//         return;

//     if (idx == 0) {
//         int newNodeIndex = L.size;
//         L.nodes[newNodeIndex].data = data;
//         L.nodes[newNodeIndex].next = L.head;
//         L.head = newNodeIndex;
//         if (L.tail == -2) {
//             L.tail = newNodeIndex;
//         }
//     } else if (idx == L.size) {
//         int newNodeIndex = L.size;
//         L.nodes[newNodeIndex].data = data;
//         L.nodes[newNodeIndex].next = -2;
//         L.nodes[L.tail].next = newNodeIndex;
//         L.tail = newNodeIndex;
//     } else {
//         int newNodeIndex = L.size;
//         L.nodes[newNodeIndex].data = data;

//         int cur = L.head;
//         for (int i = 1; i < idx; i++) {
//             cur = L.nodes[cur].next;
//         }

//         L.nodes[newNodeIndex].next = L.nodes[cur].next;
//         L.nodes[cur].next = newNodeIndex;
//     }

//     L.size++;
// }

// void erase(SList& L, size_t position) {
//     if (position >= L.size) {
//         cerr << "Indataid position for erasing" << endl;
//         return;
//     }

//     if (position == 0) {
//         int temp = L.head;
//         L.head = L.nodes[L.head].next;
//         if (L.head == -2) {
//             L.tail = -2;
//         }
//     } else if (position == L.size - 1) {
//         int temp = L.nodes[L.head].next;
//         while (L.nodes[temp].next != -2) {
//             temp = L.nodes[temp].next;
//         }
//         L.nodes[temp].next = -2;
//         L.tail = temp;
//     } else {
//         int cur = L.head;
//         for (size_t i = 0; i < position - 1; ++i) {
//             cur = L.nodes[cur].next;
//         }

//         int temp = L.nodes[cur].next;
//         L.nodes[cur].next = L.nodes[temp].next;
//     }

//     L.size--;
// }

// void printList(SList& L) {
//     int cur = L.head;
//     while (cur != -2) {
//         cout << L.nodes[cur].data << " ";
//         cur = L.nodes[cur].next;
//     }
//     cout << endl;
// }

// int main() {
//     SList L;
    

//     init(L);
//     int cur = L.head;
//     while (1) {
//         cout << L.nodes[cur].data << " ";
//         cur = L.nodes[cur].next;
//     }
//     cout << endl;

//     // // 将元素 y 插入到 x 后面, 所以+1
//     // insert(L, findElemPos(L, 1) + 1, 99);
//     // insert(L, findElemPos(L, 99) + 1, 50);
//     // insert(L, findElemPos(L, 99) + 1, 75);
//     // cout << findElemNext(L, 99) << endl;
//     // erase(L, findElemPos(L, 75) + 1);
//     // cout << findElemNext(L, 1) << endl;

//     // printList(L);

//     // int q;
//     // cin >> q;

//     // while (q--) {
//     //     int op, x, y;
//     //     cin >> op;

//     //     if (op == 1) {
//     //         cin >> x >> y;
//     //         insert(L, findElemPos(L, x) + 1, y);
//     //     } else if (op == 2) {
//     //         cin >> x;
//     //         cout << findElemNext(L, x) << endl;
//     //     } else if (op == 3) {
//     //         cin >> x;
//     //         erase(L, findElemPos(L, x) + 1);
//     //     }
//     // }

//     return 0;
// }
