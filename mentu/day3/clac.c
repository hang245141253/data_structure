#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int calc(char *s, int l, int r) {
    int op = -1; // 最低优先级的位置
    int pri = 99999; // 当前最低运算符优先级（初始化一个极大值打擂台）
    int cur_pri; // 当前运算符的优先级
    int temp = 0; // 由括号()额外增加的运算符优先级

    // 找全局运算符优先级最低的位置
    for (int i = l; i <= r; i++) {
        cur_pri = 100000;
        switch (s[i]) {
            case '+':
            case '-': cur_pri = 1 + temp; break;
            case '*':
            case '/': cur_pri = 2 + temp; break;
            case '(': temp += 100; break;
            case ')': temp -= 100; break;
        }
        // 打擂台找pri
        if (cur_pri <= pri) { // cur_pri <= pri是安全的，因为它总是考虑相同优先级的运算符。
        // 使用 (cur_pri < pri) 也是可行的，因为递归调用保证了正确的计算顺序，但这种方法可能在其他上下文中引起混淆。
            pri = cur_pri;
            op = i;
        }
    }
    // op == -1 说明是个纯数字
    if (op == -1) {
        // 把当前这段字符串转成数字
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (!isdigit(s[i])) continue;
            num = num * 10 + atoi(&s[i]);
        }
        return num;
    }

    // debug用 : 输出找到运算符优先级最低的是什么
    printf("calc find : %c op = %d\n", s[op], op);

    // 否则计算表达式两侧的值
    int a = calc(s, l, op - 1);
    int b = calc(s, op + 1, r);
    switch (s[op]) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int main() {
    char s[100];
    while (~scanf("%[^\n]", s)) {
        getchar(); // 清除卡在输入缓冲区中的'\n'
        printf("%s = %d\n", s, calc(s, 0, strlen(s) - 1));
    }
}