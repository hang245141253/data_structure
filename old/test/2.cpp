#include <iostream>
//using namespace std;

int data[10];       //数据域
int next[10];       //指针域

// 在ind结点后面添加结点p，结点p的值是val
void add(int ind, int p, int val) {
    next[ind] = p;
    data[p] = val;
    return ;
}

int main() {
    int head = 3;
    data[3] = 0;
    add(3, 5, 1);
    add(5, 2, 2);
    add(2, 7, 3);

    int p = head;
    while (p != 0)
    {
        printf("%d->", data[p]);
        p = next[p];
    }
    printf("\n");
    


    return 0;
}