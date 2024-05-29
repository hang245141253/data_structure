// priority_queue_example.cpp
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

// 用于演示STL优先队列的示例程序

int main() {
    // 构建堆
    {
        std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
        // 使用vec中的元素初始化优先队列
        std::priority_queue<int> pq(vec.begin(), vec.end());
        std::cout << "堆化后的数组: ";
        while (!pq.empty()) {
            std::cout << pq.top() << " ";
            pq.pop();
        }
        std::cout << std::endl;
    }

    // 向堆中添加元素
    {
        std::vector<int> vec = {3, 1, 4, 1, 5, 9};
        // 使用vec中的元素初始化优先队列
        std::priority_queue<int> pq(vec.begin(), vec.end());
        // 向堆中添加新元素6
        pq.push(6);
        std::cout << "添加新元素6后的堆: ";
        while (!pq.empty()) {
            std::cout << pq.top() << " ";
            pq.pop();
        }
        std::cout << std::endl;
    }

    // 从堆中移除堆顶元素
    {
        std::vector<int> vec = {3, 1, 4, 1, 5, 9};
        // 使用vec中的元素初始化优先队列
        std::priority_queue<int> pq(vec.begin(), vec.end());
        int largest = pq.top();
        pq.pop();
        std::cout << "堆顶元素（最大值）: " << largest << "\n";
        std::cout << "移除堆顶元素后的堆: ";
        while (!pq.empty()) {
            std::cout << pq.top() << " ";
            pq.pop();
        }
        std::cout << std::endl;
    }

    // 堆排序
    {
        std::vector<int> vec = {3, 1, 4, 1, 5, 9};
        // 使用vec中的元素初始化优先队列
        std::priority_queue<int> pq(vec.begin(), vec.end());
        std::vector<int> sorted_vec;
        // 从优先队列中依次取出元素并存入sorted_vec
        while (!pq.empty()) {
            sorted_vec.push_back(pq.top());
            pq.pop();
        }
        // 将结果反转以获得从小到大的顺序
        std::reverse(sorted_vec.begin(), sorted_vec.end());
        std::cout << "堆排序后的数组: ";
        for (int i : sorted_vec) std::cout << i << " ";
        std::cout << std::endl;
    }

    return 0;
}
