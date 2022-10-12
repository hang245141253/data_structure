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

// 算法2.1 顺序表的初始化
Status InitList(SqList* L) {
    L->elem = (ElemType*)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if (L->elem == NULL) {
        exit(OVERFLOW);
    }
    L->length = 0;      //未解指针，需要->指向
    (*L).listsize = LIST_INIT_SIZE; //先解指针，再用.访问。（与上等价）
    printf("Initial!\n");
    return OK;
}

// 算法2.2 顺序表的取值
Status GetElem(SqList L, int i, ElemType* e) {
    //i的含义是位序，所以i∈[1, length]
    if (i < 1 || i > L.length) {
        return ERROR;   
    }
    *e = L.elem[i - 1]; //数组下标j = 位序i - 1
    printf("GetElem %d at LOC(%d)\n", *e, i);
    return OK;
}

// 算法2.3 顺序表的查找
int LocateElem(SqList L, ElemType e) {
    for (int j = 0; j < L.length; j++) {
        if (L.elem[j] == e) {
            return j + 1;   // 位序i = 数组下标j + 1
        }
    }
    return 0;   //查找失败
}// 因为返回值有非0、1的值，所以用int 不用Status

// 算法2.4 顺序表的插入
Status ListInsert(SqList* L, int i, ElemType e) {
    if (i < 1 || i > L->length) {
        return ERROR;   //i∈[i, length]
    }
    if (L->length >= L->listsize) {
        return ERROR; // or 扩容
    }
    for (int j = L->length - 1; j >= i - 1; j--) { //记j为数组下标
        L->elem[j + 1] = L->elem[j];  //插入位置及之后元素后移
    }
    L->elem[i - 1] = e;  //在位置i插入元素 (记i - 1为数组下标)
    L->length++;         //表长+1
    return OK;
}

// 算法2.5 顺序表的删除
Status ListDelete(SqList* L, int i) {
    if (i < 1 || i > L->length) {
        return ERROR;   //i∈[i, length]
    }
    for (int j = i - 1; j < L->length - 1; j++) {
        L->elem[j] = L->elem[j + 1];    //被删除元素之后的元素前移
    }
    L->length--;        //表长-1
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