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
    int j = 1;            // 计数器j赋初值为1
    while (p && j < i) {  // p为空是到链表尾了，i<=0是非法输入
        p = p->next;      // p指向下一个结点
        ++j;              //计数器j相应+1
    }
    if (!p || j > i) {      //i>结点长度n(p为空) 或 i<=0:i值不合法
        return ERROR;
    }
    e = p->data;
    return OK;
}



int main() {
    LinkList L;  // 头指针
    InitList(&L);
    printf("%ld\n", sizeof(LNode));
    return 0;
}