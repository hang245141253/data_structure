// heap_algorithms.cpp
#include <iostream>
#include <vector>
#include <algorithm>

// 用于演示STL堆算法的示例程序

int main() {
    // 构建堆
    {
        std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
        // 将vec中的元素转换为堆
        std::make_heap(vec.begin(), vec.end());  // 第三个参数默认是less<int>()，小于号构建大根堆
        std::cout << "堆化后的数组: ";
        for (int i : vec) std::cout << i << " ";
        std::cout << std::endl;
    }

    // 向堆中添加元素
    {
        std::vector<int> vec = {3, 1, 4, 1, 5, 9};
        // 将vec中的元素转换为堆
        std::make_heap(vec.begin(), vec.end());
        // 向堆中添加新元素6
        vec.push_back(6);
        std::push_heap(vec.begin(), vec.end());  // push_back后一定要push_heap
        std::cout << "添加新元素6后的堆: ";
        for (int i : vec) std::cout << i << " ";
        std::cout << std::endl;
    }

    // 从堆中移除堆顶元素
    {
        std::vector<int> vec = {3, 1, 4, 1, 5, 9};
        // 将vec中的元素转换为堆
        std::make_heap(vec.begin(), vec.end());
        // 移除堆顶元素
        std::pop_heap(vec.begin(), vec.end()); // pop_back前一定要pop_heap
        int largest = vec.back();
        vec.pop_back();
        std::cout << "堆顶元素（最大值）: " << largest << "\n";
        std::cout << "移除堆顶元素后的堆: ";
        for (int i : vec) std::cout << i << " ";
        std::cout << std::endl;
    }

    // 堆排序
    {
        std::vector<int> vec = {3, 1, 4, 1, 5, 9};
        // 将vec中的元素转换为堆
        std::make_heap(vec.begin(), vec.end());
        // 对堆进行排序
        std::sort_heap(vec.begin(), vec.end());  // sort_heap前要make_heap保证是堆
        std::cout << "堆排序后的数组: ";
        for (int i : vec) std::cout << i << " ";
        std::cout << std::endl;
    }

    return 0;
}
