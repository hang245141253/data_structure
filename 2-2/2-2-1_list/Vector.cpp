#include <cstring>
#include <iostream>
#include <vector>
using namespace std;




/*

书面上：
数据结构从两个维度讨论：
逻辑结构、物理结构
    逻辑结构：线性与非线性
    物理结构：连续与分散

编码上：
数据结构 = 结构定义 + 结构操作（增删改查）
    int arr[10];
    int *p = new int[10];
    结构定义可使用：
    静态定义（静态区/全局区） or 动态定义（堆区）

数据结构1，线性表
    顺序表(静态、动态)、链表(静态、动态)

*/

typedef int ElemType;  // 数据元素类型约定为ElemType, 由用户在使用该数据类型时自行定义

/****************************** 结构定义 ************************************/
struct Vector {
    ElemType* data;
    int capacity, size;
};

/****************************** 结构操作 ************************************/

void init(Vector& vec) {
    vec.data = new ElemType[1];
    vec.capacity = 1;
    vec.size = 0;
}

// 扩容函数 x1.5 ~ x2之间
int expand(Vector& vec) {
    // 计算新的容量
    int newCapacity = vec.capacity * 2;

    // 分配新的内存
    ElemType* newData = new ElemType[newCapacity];

    // 检查内存分配是否成功
    if (newData == nullptr)
        return -1;  // 内存分配失败，返回错误代码

    // 使用 memcpy 将旧数据复制到新的内存中
    memcpy(newData, vec.data, vec.size * sizeof(ElemType));

    // 释放旧内存
    delete[] vec.data;

    // 更新向量的指针和容量
    vec.data = newData;
    vec.capacity = newCapacity;

    // 返回扩容前的容量
    return newCapacity / 2;
}

// 尾部插入元素，考虑会有插入失败的可能返回false
bool push_back(Vector& vec, ElemType val) {
    // 如果未初始化 vec.data == nullptr
    if (vec.data == nullptr)
        return false;

    // 如果容量不够存元素
    if (vec.size >= vec.capacity) {
        if (expand(vec) == -1)
            return false;
        // printf("expand successfully ! capacity = %d\n", vec.capacity);
    }

    // 在尾部直接插入
    vec.data[vec.size] = val;
    vec.size++;

    return true;
}

// 插入元素
bool insert(Vector& vec, int idx, ElemType val) {
    // 如果未初始化 vec.data == nullptr
    if (vec.data == nullptr)
        return false;

    // 检查位置是否有效
    if (idx < 0 || idx > vec.size)
        return false;

    // 检查容量是否足够，如果需要则扩容
    if (vec.size == vec.capacity) {
        if (expand(vec) == -1)
            return false;
        // printf("expand successfully ! capacity = %d\n", vec.capacity);
    }

    // (从后向前遍历)为新元素腾出位置
    for (int i = vec.size; i > idx; --i) {
        vec.data[i] = vec.data[i - 1];
    }

    // 插入新元素
    vec.data[idx] = val;
    vec.size++;

    return true;
}

// 删除指定位置的元素
bool erase(Vector& vec, int idx) {
    // 如果未初始化 vec.data == nullptr
    if (vec.data == nullptr)
        return false;
        
    // 检查位置是否有效
    if (idx < 0 || idx >= vec.size)
        return false;

    // (从前向后遍历)移动元素，覆盖被删除的位置
    for (int i = idx; i < vec.size - 1; ++i) {
        vec.data[i] = vec.data[i + 1];
    }

    // 减少向量的大小
    vec.size--;

    return true;
}

void clear(Vector& vec) {  // 销毁操作
    if (vec.data == nullptr)
        return;
    delete[] vec.data;
    vec.data = nullptr;
    vec.capacity = 0;
    vec.size = 0;
}

int main_test() {
    Vector vec;
    init(vec);
    // int arr[10] = {1,2,3};
    

    push_back(vec, 1);
    push_back(vec, 2);
    push_back(vec, 3);
    push_back(vec, 1);
    push_back(vec, 2);
    push_back(vec, 3);

    // 在不同位置插入元素
    insert(vec, 0, 100);
    insert(vec, 2, 300);
    insert(vec, 7, 9999);
    insert(vec, 7, -1);

    erase(vec, 2);  // 擦除v[2]
    erase(vec, 0);  // 擦除v[0]

    printf("data = %p, capacity = %d, size = %d\n", vec.data, vec.capacity, vec.size);

    // 遍历输出
    for (int i = 0; i < vec.size; i++) {
        printf("data[%d] = %d\n", i, vec.data[i]);
    }

    // 需要手动回收，否则会造成内存泄漏
    clear(vec);
    printf("data = %p, capacity = %d, size = %d\n", vec.data, vec.capacity, vec.size);

    return 0;

    /****************************** vector_STL ************************************/

    vector<ElemType> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // 在不同位置插入元素(第一个参数是迭代器)
    v.insert(v.begin(), 100);
    v.insert(v.begin() + 2, 300);
    v.insert(v.begin() + 7, 9999);
    v.insert(v.begin() + 7, -1);

    v.erase(v.begin() + 2);  // 擦除v[2]
    v.erase(v.begin());      // 擦除v[0]

    cout << "v.size = " << v.size() << " "            // 查看元素的个数
         << "v.capacity = " << v.capacity() << endl;  // 查看容器的容量

    // 遍历输出
    for (int i = 0; i < v.size(); i++) {
        printf("v[%d] = %d\n", i, v[i]);
    }

    // 迭代器遍历输出
    // for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    //     cout << *it << " ";
    // }

    return 0;
}

// https://oj.stemstar.com/problems/287
int main() {
    Vector vec[10005];
    int n, m, x, y;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        init(vec[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        push_back(vec[x], y);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < vec[i].size; j++) {
            j && printf(" ");
            printf("%d", vec[i].data[j]);
        } printf("\n");
    }
    return 0;
}