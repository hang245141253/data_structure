#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define LIST_INIT_SIZE 10

// Status视为bool型，OK即为True，ERROR即为false
typedef int Status;

// 顺序表元素类型定义
typedef int ElemType;

typedef struct {
    ElemType* elem;
    int listsize;
    int length;
} SqList;
// *在定义指针，声明指针时靠近前方，靠近后方时理解为解引用
Status InitList(SqList* L) {
    L->elem = (ElemType*)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if (L->elem == NULL) {
        exit(OVERFLOW);
    }
    L->length = 0;      //未解指针，需要->指向
    (*L).listsize = 0; //先解指针，再用.访问。（与上等价）
    printf("Initial!\n");
    return OK;
}

int main() {
    SqList L;
    InitList(&L);
    /*下面是错的
    SqList* L;  //L是存SqList类型的指针
    InitList(L);//未初始化 野指针
    */
    return 0;
}