#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l(1, 1);

    int q;
    cin >> q;
    while (q--) {
        int op, x, y;
        list<int>::iterator it = l.begin();
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            it = find(l.begin(), l.end(), x); // 链表遍历查找

            // 在 x 后面插入 y
            l.insert(++it, y);

        } else if (op == 2) {
            cin >> x;
            it = find(l.begin(), l.end(), x);

            printf("%d\n", (it++, it == l.end() ? 0 : *it));
        } else {
            cin >> x;
            it = find(l.begin(), l.end(), x);

            l.erase(++it);  // 擦除后面的元素
        }

        // print
        // cout << "List :";
        // for (it = l.begin(); it != l.end(); it++) {
        //     cout << *it << " ";
        // } cout << endl;
    }
    return 0;
}