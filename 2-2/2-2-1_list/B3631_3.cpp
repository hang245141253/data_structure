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
    int idx = mmap[x];
    auto nxt = L.nodes[idx].next;
    cout << (nxt == -1 ? 0 : L.nodes[nxt].data) << endl;
}

// 删除 x 后面的元素
void erase(SList& L, int x) {
    // int cur = L.head;
    // while (cur != -1) {
    //     if (L.nodes[L.nodes[cur].next].data == x) break;
    //     cur = L.nodes[cur].next;
    // }

    // if (cur == -1)  return;

    // L.nodes[cur].next = L.nodes[L.nodes[cur].next].next;
    int idx = mmap[x];
    L.nodes[idx].next = L.nodes[L.nodes[idx].next].next;
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
