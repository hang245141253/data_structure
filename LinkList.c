#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

// Status视为bool型，OK即为True，ERROR即为false
typedef int Status;

// 链表元素类型定义
typedef int ElemType;
/*ElemType：
既可以是基本数据类型int、float、char等；
又可以是构造数据类型struct结构体*/

typedef struct LNode {
    ElemType data;       //结点的数据域
    struct LNode* next;  //结点的指针域
} LNode, *LinkList;      // LNode* 表示结点、 LinkList表示单链表

// 算法2.6 单链表的初始化
Status InitList(LinkList* L) {             // 传入的参数是<指针变量L>的地址，指针变量表示的是结点的地址
    (*L) = (LNode*)malloc(sizeof(LNode));  // 头指针L->头结点
    (*L)->next = NULL;                     // 头结点的指针域置空
    return OK;
}

// 算法2.7 单链表的取值
Status GetElem(LinkList L, int i, ElemType* e) {
    LNode* p = L->next;   // p为指向单链表中某个结点的指针,p指向首元结点
    int j = 1;            // 计数器j赋初值为1(第1个结点是首元结点)
    while (p && j < i) {  // 循环找到第i个结点
        p = p->next;
        ++j;
    }
    if (!p || j > i) {  // i>n(p为空) 或 i<=0:i值不合法
        return ERROR;
    }
    *e = p->data;
    return OK;
}

// 算法2.8 单链表的查找
LNode* LocateElem(LinkList L, ElemType e) {
    LNode* p = L->next;          // p指向首元结点
    while (p && p->data != e) {  // 顺链域向后扫描，直到p为空 或 p所指结点的data为e时退出
        p = p->next;
    }
    return p;  // 查找成功返回值为e的结点地址怕，查找失败p为NULL
}

// 算法2.9 单链表的插入
Status ListInsert(LinkList* L, int i, ElemType e) {
    LNode* p = *L;            // p指向头结点
    int j = 0;                // 当前p指向的是第几个结点(第0个结点是头结点)
    while (p && j < i - 1) {  // 循环找到第i-1个结点
        p = p->next;
        ++j;
    }  // 循环域为[2, n] p==NULL时位置在n+1处不合法退出循环
    if (!p || j > i - 1) {
        return ERROR;
    }                                          // 可合法插入的位置有n+1个,即i∈[1, n+1]
    LNode* s = (LNode*)malloc(sizeof(LNode));  // 生成新结点*s
    s->data = e;                               // 将结点*s的数据域置为e
    s->next = p->next;                         // 将结点*s的指针域指向结点a(i)
    p->next = s;                               // 将结点*p的指针域指向结点*s
    return OK;
}

// 算法2.10 单链表的删除
Status ListDelete(LinkList* L, int i) {
    LNode* p = *L;                  // p指向头结点
    int j = 0;                      // 当前p指向的是第几个结点(第0个结点是头结点)
    while (p->next && j < i - 1) {  // p->next==NULL时,说明p位置在末尾n处
        p = p->next;
        ++j;
    }  // 循环域为[2, n—1] p->next==NULL时位置在n处不合法退出循环
    if (!(p->next) || j > i - 1) {
        return ERROR;
    }                    // 可合法插入的位置有n个,即i∈[1, n]
    LNode* q = p->next;  // 结点q临时保存被删除结点的地址以备free
    p->next = q->next;   // 删除结点的前驱 -> 删除结点的后继
    free(q);             // 释放删除结点
    return OK;
}

// 算法2.11 头插法创建单链表
void CreatList_H(LinkList* L, int n) {
    InitList(L);
    for (int i = 0; i < n; i++) {
        LNode* p = (LNode*)malloc(sizeof(LNode));  // 生成新结点*p
        scanf("%d", &p->data);                     // 输入元素至新结点*p的数据域
        p->next = (*L)->next;
        (*L)->next = p;  // 将新结点*p插入到头结点之后
    }
}

// 算法2.12 尾插法创建单链表
void CreatList_R(LinkList* L, int n) {
    InitList(L);
    LNode* r = (*L);
    for (int i = 0; i < n; i++) {
        LNode* p = (LNode*)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

// 遍历单链表 & 求表长
void PrintList(LinkList L) {
    int i = 0;
    if (L->next == NULL) {
        printf("单链表L为空表\n");
        printf("test1表长为%d\n", i);
        return ;
    }
    LNode* p = L->next; // p指向首元结点
    while (p) {
        printf("%d ", p->data);
        p = p->next;
        i++;
    }
    printf("表长为%d\n", i);
}

int main() {
    LinkList L;  // 头指针
    // InitList(&L);
    // PrintList(L);
    CreatList_R(&L, 3);
    PrintList(L);
    // printf("%ld\n", sizeof(LNode));
    return 0;
}