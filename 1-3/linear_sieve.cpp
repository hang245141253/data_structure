#include <iostream>
#include <vector>
using namespace std;

#define MAX 30
int prime[MAX + 5];

/*
线性筛：空间复杂度时间复杂度都为 O(N)
作用：筛选一定范围内所有的素数。

核心思想：每个合数只能由它的最小质因子（最低的素数）标记，
        确保每个合数只被标记一次，从而实现 O(N) 的复杂度。

mul 表示为 mul = prime[j] * i，其中 `mul` 和 `i` 有如下性质：
    - mul 中最小的素数为 prime[j]，也是最小因数。
    - i 是 mul 的最大因数（即当前处理的数）。
    - prime[j] 一定是 `i` 的最小素因子，因为 `prime[j]` 是 `i` 中最小的质数，
      满足 `i % prime[j] == 0`，即 `prime[j]` 是 `i` 的最小质因子。

    比如：
    1
    i: 2 prime[1]: 2 mul: 4
    2
    i: 3 prime[1]: 2 mul: 6
    i: 3 prime[2]: 3 mul: 9
    2
    i: 4 prime[1]: 2 mul: 8
    为什么不 4 * 3 = 12来标记12呢？
    分析一下12的全部因数：1, 2, 3, 4, 6, 12
    12应该是i = 6时候标记的，因为2是12的最小质因子

*/

void linear_sieve() {
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i])
            prime[++prime[0]] = i;             // 记录素数
                                               // cout << prime[0] << endl;
        for (int j = 1; j <= prime[0]; j++) {  // 遍历已有素数表
            int mul = i * prime[j];            // ✅ 正确初始化 mul
            if (mul > MAX)    break;  // ✅ 先判断是否超界
            prime[mul] = 1;
            // printf("i: %d prime[%d]: %d mul: %d\n", i, j, prime[j], mul);
            if (i % prime[j] == 0)
                break;  // ✅ 保证每个数只被最小质因子筛去一次
        }
    }
}

vector<int> sieve_linear(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    for (int i = 2; i <= n / 2; i++) {
        if (is_prime[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
            is_prime[i * primes[j]] = 0;
            if (i % primes[j] == 0)
                break;
        }
    }
    for (int i = n / 2 + 1; i <= n; i++) {
        if (is_prime[i])
            primes.push_back(i);
    }
    return primes;
}

int main() {
    // linear_sieve();
    // for (int i = 1; i <= prime[0]; i++) {
    //     cout << prime[i] << " ";
    // }
    // cout << endl;
    vector<int> primes = sieve_linear(100);
    for (int i = 0; i < primes.size(); i++) {
        cout << primes[i] << " ";
    }
    return 0;
}