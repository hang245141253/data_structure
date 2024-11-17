#include <cstdio>

int main() {
    int n, lowbit, d;
    scanf("%d", &n);
    lowbit = n & -n;                            // 计算 n 的最低有效位所代表的 2 的次幂值
    for (d = 0; lowbit < n; lowbit <<= 1) ++d;  // 循环左移 lowbit 直到 lowbit >= n，并记录步数
    printf("%d %d\n", lowbit, d);               // 打印 lowbit 和 d 的值
    return 0;
}

// #include <stdio.h>
// #include <math.h>

// int binary_search_steps(int length, int target) {
//     int steps = 0;
//     int low = 1, high = length;

//     while (low <= high) {
//         steps++;
//         int mid = (low + high) / 2;
//         if (mid == target) {
//             break;
//         } else if (mid > target) {
//             high = mid - 1;
//         } else {
//             low = mid + 1;
//         }
//     }

//     return steps;
// }

// int main() {
//     int length, target;

//     scanf("%lld", &target);

//     for (length = 2; length < target; length *= 2);
//     if (length == target) {
//         printf("%lld 0\n", length);
//         return 0; 
//     }
//     int steps = binary_search_steps(length, target);
//     printf("%lld %lld\n", length, steps);

//     return 0;
// }



// #include <iostream>
// using namespace std;

// int main() {
//     int K;
//     cin >> K;

//     // 找到大于等于 K 的最小的 2 的幂次
//     int min_size = 1;
//     while (min_size < K) {
//         min_size <<= 1; // 将 min_size 乘以 2，直到 min_size 大于等于 K
//     }

//     // 计算最少切割次数
//     int current_size = min_size; // 初始化当前巧克力块大小为找到的最小 2 的幂次
//     int cuts = 0; // 切割次数初始化为 0

//     // 剩余的需求大小，初始为 K
//     int remaining = K;
//     while (remaining > 0) {
//         if (current_size > remaining) {
//             // 如果当前块的大小大于剩余需求，进行切割
//             current_size /= 2; // 将当前块大小对半切割
//             cuts++; // 增加一次切割次数
//         } else {
//             // 如果当前块大小小于等于剩余需求
//             remaining -= current_size; // 分配当前块，并从剩余需求中减去这部分
//         }
//     }

//     // 输出最小巧克力块的大小和最少切割次数
//     cout << min_size << " " << cuts << endl;
//     return 0;
// }
