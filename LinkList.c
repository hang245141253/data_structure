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
    ElemType data;  //结点的数据域
    struct LNode* next; //结点的指针域
} LNode, *LinkList; //LNode* 表示结点、 LinkList表示单链表

// 算法2.6 单链表的初始化
Status InitList(LinkList* L) {  // 传入的参数是<指针变量L>的地址，指针变量表示的是结点的地址
    (*L) = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
}



int main() {
    
    return 0;
}