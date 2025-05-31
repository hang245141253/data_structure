#include <stdio.h>
#include <math.h>

long long fast_pow(long long base, long long pow, long long mod) {
    long long ret = 1;
    while (pow) {
        if (pow & 1)
            ret = (ret * base) % mod;
        pow >>= 1;
        base = (base * base) % mod;
    }
    return ret;
}

int main() {
    // 计算 a^b mod p
    int a, b, p;
    scanf("%d %d %d", &a, &b, &p);
    int bb;
    // printf("%d^%d mod %d=%lld\n", a, b, p, (long long)pow(a, b) % p); // 浮点精度问题，过大的数会丢失精度
    printf("%d^%d mod %d=%lld\n", a, b, p, fast_pow(a, b, p));
    return 0;
}