#include <iostream>
#include <list>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    list<int> nodes;
    
    // 建立链表
    for (int i = 1; i <= n; i++) {
        nodes.push_back(i);
    }

    // 处理
    auto it = nodes.begin();
    while (nodes.size() > 1) {
        for (int i = 1; i < m; i++) {
            it++;
            if (it == nodes.end()) 
                it = nodes.begin(); // 手动模拟循环链表
        }
        cout << *it << " ";
        it = nodes.erase(it); // 删除元素并更新迭代器, 新的it是原it的next
        if (it == nodes.end())
            it = nodes.begin(); // 手动模拟循环链表
    }
    cout << *it;
    return 0;
}
