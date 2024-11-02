#include <bits/stdc++.h>
using namespace std;

int main() {
    int M;
    string N;
    cin >> M >> N;
    int s = N.size();

    for (int i = 0; i < s; i++) {
        if (N[i] == '0') continue;
        i && printf("+");
        printf("%c*%d^%d", N[i], M, s - i - 1);
    }

    return 0;
}
