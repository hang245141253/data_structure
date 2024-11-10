#include <cstdio>

int main() {
  int n, lowbit, d;
  scanf("%d", &n);
  lowbit = n & -n; // 计算 n 的最低有效位所代表的 2 的次幂值
  for( d = 0; lowbit < n; lowbit <<= 1 ) ++d; // 循环左移 lowbit 直到 lowbit >= n，并记录步数
  printf("%d %d\n", lowbit, d); // 打印 lowbit 和 d 的值
  return 0;
}
