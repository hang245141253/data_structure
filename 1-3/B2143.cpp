#include <iostream>
using namespace std;

int num[35];
int i = 0;

void f(int x, int m) {
    if (x == 0) return;
    num[i++] = x % m;
    f(x / m, m);
}

int main() {
    int X, M;
    cin >> X >> M;

    f(X, M);

    // while (X) {
    //     num[i++] = X % M;
    //     X /= M;
    // }

    for (int j = i - 1; j >= 0; j--) {
        if (num[j] > 9) {
            printf("%c", 'A' - 10 + num[j]);
        } else {
            printf("%d", num[j]);
        }
    }

    return 0;
}