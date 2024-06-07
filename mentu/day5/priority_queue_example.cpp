// priority_queue_example.cpp
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

/*
大根堆：
priority_queue<int> q;
priority_queue<int, vector<int>, less<int>> q;
小根堆：
priority_queue<int, vector<int>, greater<int>> q;


第二个参数的默认值：vector<T> 第三个参数的默认值less<T>

常用的成员函数top() empty() size() push(x) pop()

*/


// 用于演示STL优先队列的示例程序

int main() {
    // 构建堆
    {
        vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
        // 使用vec中的元素初始化优先队列
        priority_queue<int, vector<int>, less<int>> pq(vec.begin(), vec.end());
        cout << "堆化后的数组: ";
        while (!pq.empty()) {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }

    // 向堆中添加元素
    {
        vector<int> vec = {3, 1, 4, 1, 5, 9};
        // 使用vec中的元素初始化优先队列
        priority_queue<int> pq(vec.begin(), vec.end());
        // 向堆中添加新元素6
        pq.push(6);
        cout << "添加新元素6后的堆: ";
        while (!pq.empty()) {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }

    // 从堆中移除堆顶元素
    {
        vector<int> vec = {3, 1, 4, 1, 5, 9};
        // 使用vec中的元素初始化优先队列
        priority_queue<int> pq(vec.begin(), vec.end());
        int largest = pq.top();
        pq.pop();
        cout << "堆顶元素（最大值）: " << largest << "\n";
        cout << "移除堆顶元素后的堆: ";
        while (!pq.empty()) {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }

    // 堆排序
    {
        vector<int> vec = {3, 1, 4, 1, 5, 9};
        // 使用vec中的元素初始化优先队列
        priority_queue<int> pq(vec.begin(), vec.end());
        vector<int> sorted_vec;
        // 从优先队列中依次取出元素并存入sorted_vec
        while (!pq.empty()) {
            sorted_vec.push_back(pq.top());
            pq.pop();
        }
        // 将结果反转以获得从小到大的顺序
        reverse(sorted_vec.begin(), sorted_vec.end());
        cout << "堆排序后的数组: ";
        for (int i : sorted_vec) cout << i << " ";
        cout << endl;
    }

    return 0;
}
