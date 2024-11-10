#include <iostream>
using namespace std;

int main() {
    long long T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        if (n == m) {
            printf("0\n");
        } else if ((n | m) == n || (n | m) == m) {
            printf("1\n");
        } else {
            printf("2\n");
        }
    }
    return 0;
}