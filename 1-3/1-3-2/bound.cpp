#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {  // 0  1  2  3  4  5  6  7
    int arr1[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    int arr2[] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
    //  lower 带等号 找第一个1 也就是最低的
    cout << lower_bound(arr1, arr1 + 10, 1) << endl;  //  第一个idx >= x的位置
    cout << &arr1[5] << endl;
    //  upper 不带等号 找最后一个1的后面一个位置 也就是最高的
    cout << upper_bound(arr2, arr2 + 10, 1) - 1 << endl;  //  第一个idx > x的位置
    cout << &arr2[4] << endl;
    return 0;
}