#include <bits/stdc++.h>
using namespace std;

int main() {
    int M;
    string N;
    cin >> M >> N;
    reverse(N.begin(), N.end());
    int s = N.size();

    for (int i = 0; i < s; i++, N.pop_back()) {
        char n = N[N.size() - 1] - '0';
        if (n % 10 == 0) continue;
        i && printf("+");
        printf("%d*%d^%d", n % 10, M, s - i - 1);
    }

    return 0;
}
