#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    template<typename T>
    class heap : public vector<T> {  // 继承vector<T>的公共接口
    public:
        // 模板(构造)函数
        template<typename Func_T>
        heap(Func_T cmp) : cmp(cmp) {} 

        void push(const T &a) { // &引用而不是拷贝，节约开销，const防止a的值被修改
            this->push_back(a);
            push_heap(this->begin(), this->end(), cmp);
        }

        void pop() {
            pop_heap(this->begin(), this->end(), cmp);
            this->pop_back();
        }

        T &top() { // &引用，可访问、修改堆顶。不加&只能访问一个拷贝值，不能修改
            return this->at(0);
        }

    // private:
        function<bool(T, T)> cmp; // 相当于函数指针
    };

    // 手动写比较规则，大顶堆是小于号
    struct CMP {  
        bool operator()(vector<int> a, vector<int> b) {
            return a[0] + a[1] < b[0] + b[1];
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // 堆中的元素是长度为2的vector，数组中的两位分别代表数组中的第一个值和第二个值
        heap<vector<int>> h{CMP()};
        vector<int> tmp(2);
        for (auto x : nums1) {
            for (auto y : nums2) {
                tmp[0] = x, tmp[1] = y;
                h.push(tmp);
                if (h.size() > k) h.pop();
            }
        }
        return h;
    }
};