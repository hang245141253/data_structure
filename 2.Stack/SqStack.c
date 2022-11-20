#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define STACK_INIT_SIZE 5
#define STACKINCREMENT 5

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define RED(a) COLOR(a, 31)
#define GREEN(a) COLOR(a, 32)

// Status视为bool型，OK即为True，ERROR即为false
typedef int Status;

// 顺序表元素类型定义
typedef int SElemType;
/*ElemType：
既可以是基本数据类型int、float、char等；
又可以是构造数据类型struct结构体*/

typedef struct {
    SElemType* base;    // 栈底指针
    SElemType* top;     // 栈顶指针
    int stacksize;      //栈可用最大容量
} SqStack;

// 算法3.1 顺序栈的初始化
Status InitStack(SqStack* S) {
    if (S == NULL) return ERROR;
    S->base = (SElemType*)malloc(sizeof(SqStack) * STACK_INIT_SIZE);
    if (!S->base) {
        exit(OVERFLOW);
    }
    S->top = S->base;   // top初始为base 空栈
    S->stacksize = STACK_INIT_SIZE;
    printf(GREEN("初始化ok, 栈长度为%d\n"), S->stacksize);
    return OK;
}

Status DestroyStack(SqStack *S) {
    free(S->base);      // malloc动态申请的空间
    S->base = NULL;
    S->top = NULL;
    S->stacksize = 0;
    return OK;
}

Status StackPrint(SqStack S) {
    SElemType* p = S.base;
    if (S.base == NULL) {
        return ERROR;
    }
    while (p < S.top) {
        printf(GREEN("%d "), *p++);
    }
    printf("\n");
}

// 算法3.2 顺序栈的入栈
Status Push(SqStack* S, SElemType e) {
    if (S == NULL || S->base == NULL) {
        printf(RED("栈未成功初始化!\n"));
        return ERROR;
    }
    if (S->top - S->base == S->stacksize) {
        printf(RED("栈满,入栈失败!\n"));
        return ERROR;
    }
    *S->top++ = e;
    // printf("S.top = %p \nS.base = %p \n", S->top, S->base);
    printf("当前栈有%ld个元素 ", (S->top - S->base));
    StackPrint(*S);
    return OK;
}

// 算法3.3 顺序栈的出栈
Status Pop(SqStack* S, SElemType* e) {
    if (S == NULL || S->base == NULL) return ERROR;
    if (S->top == S->base) {
        printf(RED("栈空,出栈失败！\n"));
        return ERROR;    // 栈空
    }
    e = --S->top;
    printf("元素%d出栈 ", *e);
    StackPrint(*S);
    return OK;    
}

// 算法3.4 取顺序栈的栈顶元素
SElemType GetTop(SqStack S) {
    if (S.base == NULL || S.base == S.top) return ERROR;
    return --S.top;
}

int main() {
    SqStack S = {NULL, NULL, 0};
    InitStack(&S);
    Push(&S, 123);
    Push(&S, 234);
    Push(&S, 345);
    Push(&S, 456);
    Push(&S, 567);
    Push(&S, 999);

    Pop(&S, NULL);
    Pop(&S, NULL);
    Pop(&S, NULL);
    Pop(&S, NULL);
    Pop(&S, NULL);
    Pop(&S, NULL);
    
    DestroyStack(&S);
    return 0;
}