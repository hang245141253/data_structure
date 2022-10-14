#include <stdio.h>

typedef int* zhengshuzhizhen;

typedef int *intz;

int main() {
    zhengshuzhizhen i;
    intz j;

    int a;

    i = &a;

    j = &a;

    printf("i zhizhen=%p \nj zhizhen=%p\n",i, j);

    return 0;
}