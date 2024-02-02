#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

string s;
/*
map的底层是红黑树
map定义类似数组的东西，但是是没有边界的

unordered_map是无序的、map是有序的

set底层也是红黑树，小顶堆
set.begin()是堆顶元素

*/

int main(int argc, char const *argv[]) {
    map<int, int> arr;  // 定义一个int到int的数组

    arr[-100] = 123;  // 正常的数组是从数组下标0开始的
                      // 但是，我们的arr是map，它的key是int，所以整个int范围都是合法的
                      // 所以可以下标为负数

    // 遍历map
    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        cout << iter->first << " "
             << iter->second << endl;
    }  // iter迭代器，指针 first是key second是value

    set<int> s;
    s.insert(3);
    s.insert(5);
    s.insert(2);
    s.insert(3);
    cout << *s.begin() << endl;
    s.erase(s.begin());
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << " ";
    }

    return 0;
}