#include <iostream>
using namespace std;

string s;
struct node {
    int l, r;    // 指针域 双向链表
    string data;   // 数据域
} L[50005];

int idx = 1, pre = 0;

int main() {
    int n;
    cin >> n;
    char op;

    // 初始化第一个网址节点
    L[0].l = 0;
    L[0].r = -1;

    // 循环处理每个操作
    while (n--) {
        cin >> op;
        if (op == 'v') {
            // 访问操作
            cin >> L[idx].data;
            cout << L[idx].data << endl;

            // 更新前后关系 
            L[idx].l = pre;
            L[pre].r = idx;
            L[idx].r = -1;  // 新访问的网址后面暂时没有网址
            pre = idx++;    // 更新当前网址索引
        } else if (op == 'b') {
            // 后退操作
            if (L[pre].l == 0)
                cout << "?" << endl;  // 无前一个网址，输出 "?"
            else {
                pre = L[pre].l;
                cout << L[pre].data << endl;  // 输出前一个网址的字符串
            }
        } else if (op == 'f') {
            // 前进操作
            if (L[pre].r == -1)
                cout << "?" << endl;  // 无后一个网址，输出 "?"
            else {
                pre = L[pre].r;
                cout << L[pre].data << endl;  // 输出后一个网址的字符串
            }
        }
    }

    return 0;
}