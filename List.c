#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 结构定义
typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct List {
    Node head;
    int len;
} List;

Node* initNode(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = val;
    n->next = NULL;

    return n;
}

void freeNode(Node* n) {
    if (n) free(n);
    return ;
}

List* initList() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;
    l->len = 0;

    return l;
}

void freeList(List* l) {
    if (!l)  return ;
    Node *p = l->head.next, *tmp; // bug:不是&(l->head)
    while (p) {
        tmp = p;
        p = p->next;
        freeNode(tmp);
    }
    free(l);
    return ;
}

// 插入节点
int insertNode(List* l, int idx, Node* n) {
    if (!l) return 0;
    if (idx < 0 || idx > l->len)    return 0;
    // 找到插入位置的前一个位置 List->head带头结点
    Node *p = &(l->head); // 取头结点的地址:链表指针 指向的结点的 地址
    while (idx--) { //循环idx次
        p = p->next;
    }
    // 插入结点
    n->next = p->next;
    p->next = n;
    // len++
    l->len++;

    return 1;
}

// 赋值并插入结点
int insertVal(List *l, int idx, int val) {
    Node *n = initNode(val);
    if (!insertNode(l, idx, n)) {
        // 插入失败释放结点
        freeNode(n);
        return 0;
    }
    return 1;
}

int deleteNode(List* l, int idx) {
    if (!l) return 0;
    if (idx < 0 || idx >= l->len)    return 0; // 带=，此处已经考虑到空链表即len=0的情况
    Node *p = &(l->head);
    while (idx--) {
        p = p->next;
    }
    Node *tmp = p->next;
    p->next = p->next->next; // p->next = tmp->next;

    freeNode(tmp);
    l->len--;

    return 1;
}

void showList(List* l) {
    if (!l) return ;
    printf("List(%d) = [", l->len);
    for (Node *p = l->head.next; p; p = p->next) {
        printf("%d->", p->val);
    }
    printf("NULL]\n");
    return ;
}

int reverse(List *l) {
    if (!l) return 0;
    // 记录0号结点位置
    Node *p = l->head.next, *tmp;
    // 清空原链表
    l->head.next = NULL;
    l->len = 0;
    // 头插法遍历原链表
    while (p) {
        tmp = p->next;  // tmp遍历下一个待处理的结点
        insertNode(l, 0, p); // 0为头插,头插p
        p = tmp;    // 更新p,准备下一次头插
    }
    printf("*******rev*******\n");
    return 1;
}

int main() {
    srand(time(0));
    List *l = initList();
    int cnt = 20;
    while (cnt--) {
        int val = rand() % 100;
        int opt = rand() % 4;
        int idx = rand() % (l->len + 3) - 1; // 取两边非法数值

        switch (opt) {
            case 0:
            case 1:
            case 2:
                printf("insert %d at %d, res = %s\n", val, idx,
                        insertVal(l, idx, val) ? "SUCCESS" : "FAILED");
                break;
            case 3:
                printf("delete at %d, res = %s\n", idx,
                        deleteNode(l, idx) ? "SUCCESS" : "FAILED");
                break;
        }
        showList(l);
    }
    reverse(l), showList(l);
    freeList(l);
    return 0;
}

