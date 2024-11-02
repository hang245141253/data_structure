#include <iostream>
using namespace std;

int main() {
    long long n, a;
    cin >> n >> a;
    for (long long i = 1, tmp; i < n; i++) {
        cin >> tmp;
        a ^= tmp;
    }
    cout << a << " " << 0 << endl;
    return 0;
}