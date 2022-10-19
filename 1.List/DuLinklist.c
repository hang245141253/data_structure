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

typedef struct DuLNode {
    ElemType data;
    struct DuLNode* prior;
    struct DuLNode* next;
} DuLNode, *DuLinkList;

// 双向链表初始化(算法2.6)
Status InitDuList_L(DuLinkList* L) {
    *L = (DuLNode*)malloc(sizeof(DuLNode));
    if (*L == NULL) exit(OVERFLOW);   // 初始化失败
    (*L)->next = (*L)->prior = NULL;  // 前驱 后继 置空
    return OK;
}

// 按位取值(算法2.7)
DuLNode* GetElem(DuLinkList L, int i) {
    //在带头结点的双向链表L中查找第i个元素，返回结点的地址
    DuLNode* p = L->next;  // p为指向单链表中某个结点的指针,p指向首元结点
    int j = 1;             // 计数器j赋初值为1(第1个结点是首元结点)
    while (p && j < i) {   // 循环找到第i个结点
        p = p->next;
        ++j;
    }
    if (!p || j > i) {  // i>n(p为空) 或 i<=0:i值不合法
        return ERROR;
    }
    return p;
}

// 算法2.13 双向链表的插入
Status ListInsert_DuL(DuLinkList* L, int i, ElemType e) {
    DuLNode *p, *s;
    if (!(p = GetElem(*L, i))) {  // p==NULL 则i元素不存在
        printf("插入失败ERROR!\n");
        return ERROR;
    }
    p = p->prior;  // p指针前移，使用不同于书 p的后插
    s = (DuLNode*)malloc(sizeof(DuLNode));
    s->data = e;
    s->next = p->next;                          // 图2.20的③
    (p->next != NULL) && (p->next->prior = s);  // 图2.20的④ 实现尾插
    s->prior = p;                               // 图2.20的①
    p->next = s;                                // 图2.20的②
    // s->prior = p->prior; // 新结点s先连接前面
    // p->prior->next = s;  // 前面结点连接新结点s
    // s->next = p;         // 新结点s连接后面
    // p->prior = s;        // 后面结点连接s结点
    printf("在位置%d插入元素%d\n", i, e);
    return OK;
}

// 算法2.14 双向链表的删除
Status ListDelete_DuL(DuLinkList* L, int i) {
    DuLNode* p;
    if (!(p = GetElem(*L, i))) {  // p==NULL 则i元素不存在
        printf("删除失败ERROR!\n");
        return ERROR;
    }
    printf("删除位置%d的元素,被删除的元素值为%d\n", i, p->data);
    p->prior->next = p->next;                          // 图2.21的①
    (p->next != NULL) && (p->next->prior = p->prior);  // 图2.21的②
    free(p);
    return OK;
}

// 尾插法创建双向链表(算法2.12)
void CreatDuList_R(DuLinkList* L, int n) {
    InitDuList_L(L);
    DuLNode* r = *L;
    for (int i = 0; i < n; i++) {
        DuLNode* p = (DuLNode*)malloc(sizeof(DuLNode));
        // scanf("%d", &p->data);
        p->data = i + 1;    // 输入元素
        p->next = r->next;
        p->prior = r;
        r->next = p;
        r = p;
    }
}

// 遍历单链表 & 求表长
void PrintList(DuLinkList L) {
    int i = 0;
    if (L->next == NULL) {
        printf("双向链表L为空表\n");
        printf(GREEN("表长为%d\n"), i);
        return;
    }
    DuLNode* p = L->next;  // p指向首元结点
    while (p) {
        printf(GREEN("%d "), p->data);
        p = p->next;
        i++;
    }
    printf(GREEN("表长为%d\n"), i);
}

void DestoryDuList(DuLinkList* L) {
    // 从首元结点销毁,直至为空表时free(L)
    while ((*L)->next) {
        ListDelete_DuL(L, 1);
    }
    free(*L);
    printf("销毁链表L\n");
    return ;
}

int main() {
    DuLinkList L;
    CreatDuList_R(&L, 5);
    ListInsert_DuL(&L, 1, 666);
    ListDelete_DuL(&L, 1);
    PrintList(L);
    DestoryDuList(&L);
    PrintList(L);
    return 0;
}