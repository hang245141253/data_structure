#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

// 定义一个堆类，继承自 vector<int>
class Heap : public vector<int> {
public:
    // 构造函数，接受一个比较函数
    Heap(function<bool(int, int)> cmp) : cmp(cmp) {}
    
    // 向堆中添加元素，并维护堆的性质
    void push(const int &a) {
        this->push_back(a); // 将新元素添加到 vector 的末尾
        push_heap(this->begin(), this->end(), cmp); // 调整堆，使其保持性质
    }
    
    // 移除堆顶元素，并维护堆的性质
    void pop() {
        pop_heap(this->begin(), this->end(), cmp); // 将堆顶元素移到末尾
        this->pop_back(); // 移除末尾元素
    }
    
    // 返回堆顶元素
    int &top() {
        return this->at(0); // 堆顶元素始终位于 vector 的第一个位置
    }
    
private:
    // 比较函数，用于维护堆的性质
    function<bool(int, int)> cmp;
};

int main() {
    // 创建一个大顶堆，使用 greater<int>() 作为比较函数
    Heap maxHeap{greater<int>()};  // 大顶堆，值越小优先级越小
    // 创建一个小顶堆，使用 less<int>() 作为比较函数
    Heap minHeap{less<int>()};     // 小顶堆，值越大优先级越小
    
    // 向大顶堆中添加元素
    maxHeap.push(3); 
    maxHeap.push(2); 
    maxHeap.push(4); 
    maxHeap.push(1);
    
    // 向小顶堆中添加元素
    minHeap.push(3); 
    minHeap.push(2); 
    minHeap.push(4); 
    minHeap.push(1);

    // 打印并移除大顶堆中的元素
    cout << "MaxHeap: ";
    while (maxHeap.size()) { // 当堆不为空时
        cout << maxHeap.top() << " "; // 打印堆顶元素
        maxHeap.pop(); // 移除堆顶元素
    } 
    cout << endl;

    // 打印并移除小顶堆中的元素
    cout << "MinHeap: ";
    while (minHeap.size()) { // 当堆不为空时
        cout << minHeap.top() << " "; // 打印堆顶元素
        minHeap.pop(); // 移除堆顶元素
    } 
    cout << endl;

    return 0;
}



// #include <iostream>
// #include <vector>
// #include <functional>
// using namespace std;

// template<typename T>
// class Heap : public vector<T> {
// public:
//     template<typename Func_T>
//     Heap(Func_T cmp) : cmp(cmp) {}
//     void push(const T &a) {
//         this->push_back(a);
//         push_heap(this->begin(), this->end(), cmp);
//         return ;
//     }
//     void pop() {
//         pop_heap(this->begin(), this->end(), cmp);
//         this->pop_back();
//         return ;
//     }
//     T &top() {
//         return this->at(0);
//     }
// private:
//     function<bool(T, T)> cmp;
// };


// int main() {
//     Heap<int> h1{less<int>()};    //大顶堆，值越小优先级越小
//     Heap<int> h2{greater<int>()}; // 小顶堆，值越大优先级越小
    
//     h1.push(3); h1.push(2); h1.push(4); h1.push(1);
//     h2.push(3); h2.push(2); h2.push(4); h2.push(1);

//     while (h1.size()) {
//         cout << h1.top() << " ";
//         h1.pop();
//     } cout << endl;

//     while (h2.size()) {
//         cout << h2.top() << " ";
//         h2.pop();
//     } cout << endl;

//     return 0;
// }