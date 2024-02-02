#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *data;
    int top, size;
} Stack;


// 初始化
Stack* initStack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;    // 虚拟位置-1表示空栈
    return s;
}

// 释放
void freeStack(Stack **s) {
    if (!(*s)) return ;
    free((*s)->data);
    free(*s);
    *s = NULL;
    return ;
}

int push(Stack *s, int val) {
    if (!s) return 0;
    if (s->top == s->size - 1)  return 0;
    s->data[++s->top] = val;
    return 1;
}

int main() {
    Stack *s = initStack(5);
    printf("%p\n", s);
    freeStack(&s);
    printf("%p\n", s);
    return 0;
}