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

// 顺序表元素类型定义
typedef int ElemType;
/*ElemType：
既可以是基本数据类型int、float、char等；
又可以是构造数据类型struct结构体*/

typedef struct {
    ElemType* elem;
    int listsize;
    int length;
} SqList;
// *在定义指针、声明指针时靠近前方，靠近后方时理解为解引用

// 算法2.1 顺序表的初始化
Status InitList(SqList* L) {
    L->elem = (ElemType*)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if (L->elem == NULL) {
        exit(OVERFLOW);
    }
    L->length = 0;                   //未解指针，需要->指向
    (*L).listsize = LIST_INIT_SIZE;  //先解指针，再用.访问。（与上等价）
    printf("Initial!\n");
    return OK;
}

// 算法2.2 顺序表的取值
Status GetElem(SqList L, int i, ElemType* e) {
    // i的含义是位序，所以i∈[1, length]
    if (i < 1 || i > L.length) {
        return ERROR;
    }
    *e = L.elem[i - 1];  //数组下标j = 位序i - 1
    printf("GetElem LOC(%d) to e=%d\n", i, *e);
    return OK;
}

// 算法2.3 顺序表的查找
int LocateElem(SqList L, ElemType e) {
    for (int j = 0; j < L.length; j++) {
        if (L.elem[j] == e) {
            return j + 1;  // 位序i = 数组下标j + 1
        }
    }
    return 0;  //查找失败
}  // 因为返回值有非0、1的值，所以用int 不用Status

// 算法2.4 顺序表的插入
Status ListInsert(SqList* L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) {  // length + 1则可以直接插入尾部
        return ERROR;                  // i∈[i, length + 1]
    }
    if (L->length >= L->listsize) {
        ElemType* newbase = (ElemType*)realloc(L->elem,
                                               (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (newbase == NULL) {
            exit(OVERFLOW);
        }
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
        printf(GREEN("expand succeed! and now L.listsize = %d\n"), L->listsize);
        // return ERROR;  // or 扩容
    }
    for (int j = L->length - 1; j >= i - 1; j--) {  //记j为数组下标
        L->elem[j + 1] = L->elem[j];                //插入位置及之后元素后移
    }
    L->elem[i - 1] = e;  //在位置i插入元素 (记i - 1为数组下标)
    L->length++;         //表长+1
    return OK;
}

// 算法2.5 顺序表的删除
Status ListDelete(SqList* L, int i) {
    if (i < 1 || i > L->length) {
        return ERROR;  // i∈[i, length]
    }
    for (int j = i - 1; j < L->length - 1; j++) {
        L->elem[j] = L->elem[j + 1];  //被删除元素之后的元素前移
    }
    L->length--;  //表长-1
    return OK;
}

int main() {
    SqList L;
    InitList(&L);
    printf("\n*********************\n");
    /*下面是错的
    SqList* L;  //L是存SqList类型的指针
    InitList(L);//未初始化 野指针
    */

    // 每个位置插入对应位序i的值
    for (int j = 0; j < L.listsize; j++) {
        L.elem[j] = j + 1;  // 数组下标 + 1 = 位序
        L.length++;
    }

    // 遍历
    for (int j = 0; j < L.listsize; j++) {
        // j && printf(" ");
        printf("L.elem[%d] is %d\n", j, L.elem[j]);
    }
    printf("length is %d\n", L.length);
    printf("\n*********************\n");

    // 取值
    int e;
    printf("GetElem %d(1 == succeed)", GetElem(L, 5, &e));
    printf(", e value is %d\n", e);
    printf("\n*********************\n");

    // 查找
    printf("LocateElem value e=5 at LOC(%d)\n", LocateElem(L, e));
    printf("\n*********************\n");

    int index = 10;
    int value = 100;
    int value2 = 200;

    // 删除
    printf("ListDelete %d(1 == succeed)", ListDelete(&L, index));
    printf(", length is %d", L.length);
    printf(", Delete LOC(%d)\n", index);
    for (int j = 0; j < L.length; j++) {
        printf("L.elem[%d] is %d\n", j, L.elem[j]);
    }
    printf("\n*********************\n");

    // 插入1
    printf("ListInsert %d(1 == succeed)", ListInsert(&L, index, value));
    printf(", length is %d", L.length);
    printf(", Insert %d at LOC(%d)\n", value, index);
    for (int j = 0; j < L.length; j++) {
        printf("L.elem[%d] is %d\n", j, L.elem[j]);
    }

    // 插入2
    printf("ListInsert %d(1 == succeed)", ListInsert(&L, index, value2));
    printf(", length is %d", L.length);
    printf(", Insert %d at LOC(%d)\n", value2, index);
    for (int j = 0; j < L.length; j++) {
        printf("L.elem[%d] is %d\n", j, L.elem[j]);
    }

    return 0;
}