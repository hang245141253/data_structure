#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 结构定义
typedef struct Vector {
    int *data;
    int size, len;
} Vec;

Vec* init(int s) {
    Vec *v = (Vec *)malloc(sizeof(Vec));
    v->data = (int *)malloc(sizeof(int) * s);
    v->size = s;
    v->len = 0;
    printf("init success\n");
    return v;
}

void freeVec(Vec *v) {
    if (!v) return ;
    free(v->data);
    free(v);
    printf("free success\n");
    return ;
}

void show(Vec *v) {
    if (!v) return ;
    printf("Vector(%d) = [", v->len);
    for (int i = 0; i < v->len; i++) {
        i && printf(" ");
        printf("%d", v->data[i]);
    }
    printf("]\n");
    return ;
}

int expand(Vec *v) {
    if (!v) return 0;
    int expsize = v->size, *tmp = NULL;
    while (expsize) {
        tmp = (int *)realloc(v->data ,sizeof(int) * (v->size + expsize));
        if (tmp) break;
        expsize >>= 1;
    }
    if (!tmp) {
        printf("expand failed!\n");
        return 0;
    }
    v->data = tmp;
    v->size += expsize;
    printf("expand success\n");
    return 1;
}

int insert(Vec *v, int ind, int val) {
    if (!v) return 0;
    if (ind < 0 || ind > v->len) return 0;
    if (v->len == v->size) expand(v);
    memcpy(v->data + ind + 1, v->data + ind, sizeof(int) * (v->len - ind)); 
    // 从后向前移动，否则会覆盖i∈[0, len) 
    // for (int i = v->len; i > idx; i--) {
    //     v->data[i] = v->data[i - 1];
    // }
    v->data[ind] = val;
    v->len++;
    return 1;
}

int delete(Vec *v, int ind) {
    if (!v) return 0;
    if (ind < 0 || ind >= v->len) return 0;
    memcpy(v->data + ind, v->data + ind + 1, sizeof(int) * (v->len - ind - 1));
    // 从前向后移动，覆盖删除i∈[0, len) 
    // for (int i = idx + 1; i < v->len; i++) {
    //     v->data[i - 1] = v->data[i];
    // }
    v->len--;
    return 1;
}

int main() {
    srand(time(0));
    Vec *v = init(1);
    int cnt = 20;
    while (cnt--) {
        int val = rand() % 100;
        int op = rand() % 4;
        int ind = rand() % (v->len + 3) - 1;

        switch (op) {
            case 0:
            case 1:
            case 2:
                printf("insert %d at %d, ret = %d\n", val, ind, insert(v, ind, val));
                break;
            case 3:
                printf("remove at %d, ret = %d\n", ind, delete(v, ind));
                break;
        }
        show(v);
    }
    
    return 0;
}