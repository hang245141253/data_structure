#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define MAX 100
int prime[MAX + 5];

// 最简单版本的写法
void init() {
    for (int i = 2; i <= MAX; i++) {
        if (prime[i]) continue; // 1: not prime, if(1) do nothing
        for (int j = 2 * i; j <= MAX; j += i) {
            prime[j] = 1;
        }
    }
}

// 优化1
// 最简单版本的写法
void init1() {
    for (int i = 2; i <= MAX; i++) {
        if (prime[i]) continue; // 1: not prime, if(1) do nothing
        prime[++prime[0]] = i;  // prime[0] is cnt
        // for (int j = 2 * i; j <= MAX; j += i) {
        // for (int j = i * i; j <= MAX; j += i) {  // 优化2
        for (int j = i; j <= MAX / i; j++) {        // 优化3
            prime[j * i] = 1;
        }
    }
}

// 最终版
void init2() {
    for (int i = 2; i * i <= MAX; i++) {  // ✅ 只检查到 sqrt(MAX)
        if (prime[i]) continue; // 1: not prime
        prime[++prime[0]] = i;  // 记录素数
        for (int j = i; j <= MAX / i; j++) {  // ✅ 从 i^2 开始标记合数
            prime[j * i] = 1;
        }
    }
    
    /*
        只有 i <= sqrt(MAX) 的时候，此时的 i 才有资格标记
        当i > sqrt(MAX)时，i * j > MAX，不会标记任何数
        所以上半部分的代码只会标记 sqrt(MAX) 之前的合数
        剩下未被标记的数都是素数
    */

    // 处理 sqrt(MAX) 之后的素数
    for (int i = sqrt(MAX) + 1; i <= MAX; i++) {
        if (!prime[i])    prime[++prime[0]] = i;
    }
}


// vector<int> sieve_Eratosthenes(int n) {
//     vector<int> prime;
//     vector<bool> is_prime(n + 1, true);

//     for (int i = 2; i * i <= n; i++) {
//         if (is_prime[i]) {
//             prime.push_back(i);

//             for (int j = i * i; j <= n; j += i) {
//                 is_prime[j] = false;
//             }
//         }
//     }

//     for (int i = sqrt(n) + 1; i <= n; i++) {
//         if (is_prime[i]) {
//             prime.push_back(i);
//         }
//     }

//     return prime;
// }

int main() {
    // 方法0
    // init();
    // for (int i = 2; i <= MAX; i++) {
    //     if (!prime[i]) cout << i << " ";
    // } cout << endl;

    // 方法1
    // init1();
    // for (int i = 1; i <= prime[0]; i++) {
    //     cout << prime[i] << " ";
    // } cout << endl;

    // 方法2
    init2();
    for (int i = 1; i <= prime[0]; i++) {
        cout << prime[i] << " ";
    } cout << endl;
    
    // vector<int> primes = std::move(sieve_Eratosthenes(100));
    // for (int i = 0; i < primes.size(); i++) {
    //     cout << primes[i] << " ";
    // } cout << endl;
    return 0;
}