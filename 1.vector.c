/*************************************************************************
	> File Name: 1.vector.c
	> Author: 
	> Mail: 
	> Created Time: Thu Nov 18 13:24:51 2021
 ************************************************************************/
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

typedef struct Vector {
    int *data;      //记录连续存储空间的首地址 int型
    int size, length;       //存储空间的容量，当前空间下已经存在元素的个数
} Vector;

Vector *init(int n) {       //初始化操作(指针函数，返回值为地址值，本质是函数)      n表容量大小为n个元素的存储空间
    Vector *v = (Vector *)malloc(sizeof(Vector)); //初始化生成一个顺序表；  
    v->data = (int *)malloc(sizeof(int) * n); //malloc向堆空间动态申请空间，堆空间很大，栈空间较小8MB
    v->size = n;
    v->length = 0;
    return v;       //return的是地址
}

int expand(Vector *v) {
    int extr_size = v->size;
    int *p;
    while(extr_size) {
        p = (int *)realloc(v->data, sizeof(int) * (v->size + extr_size));
        if (p != NULL) break;
        extr_size >>= 1; //右移一位是除以2
    }
    if (p == NULL) return 0; //此处判断必要，因为上面的while循环可因p非空或者extr_size缩为0退出
    v->data = p;
    v->size += extr_size;
    return 1;
}
//int expand(Vector *v) {   //错误写法，因为一旦realloc失败返回值则为NULL，造成内存泄漏与数据丢失 
//    v->data = (int *)realloc(v->data, sizeof(int) * (v->size * 2));
//    v->size <<= 1; //左移一位是乘2
//    return 1;
//}

int insert(Vector *v, int index, int value) {
    if (v == NULL) return 0;
    if (v->length == v->size) {
        if(!expand(v)) return 0;
        printf(GREEN("success to expand! the size = %d\n"), v->size);
    }           //判断容量是否满了,满了就扩容  
    if (index < 0 || index > v->length) return 0; //判断插入合法性
    for (int i = v->length; i > index; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[index] = value;
    v->length += 1;
    return 1;
}

int erase (Vector *v, int index) {
    if (v == NULL) return 0;
    if (index < 0 || index >= v->length) return 0;
    for (int i = index + 1; i < v->length; i++) {   //index + 1 是为了防止下面写v->data[i + 1]造成数组访问越界
        v->data[i - 1] = v->data[i];
    }
    v->length -= 1;
    return 1;
}

void output(Vector *v) {
    if (v == NULL) return ;
    printf("Vector :[");
    for (int i = 0; i < v->length; i++) {
        i && printf(" ");   //除了i=0时不输出空格；i非零时才可输出成功，printf函数返回值为1
        printf("%d", v->data[i]);
    }
    printf("]\n");
    return;
}

void clear(Vector *v) {         //销毁操作
    if (v == NULL) return ;
    free(v->data);
    free(v);
    return;
}

int main() {
    srand(time(0));  //初始化随机种子，引入头文件time.h
    #define MAX_OP 30
    Vector *v = init(1);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4;  //op值为3时候才擦除，擦除率为25%
        int value = rand() % 100;
        int index = rand() % (v->length + 3) - 1; //此时index取值范围为[-1, v->length + 1]
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("insert %d at %d to Vector = %d\n", value, index, insert(v, index, value));
            } break;
            case 3: {
                printf("erase a item at %d form Vector = %d\n", index, erase(v, index));
            } break;
        }
        output(v), printf("\n"); //逗号表达式
    }
    #undef MAX_OP
    clear(v);
    return 0;
}
