#include <iostream>
using namespace std;

typedef unsigned int uint;

int main() {
    uint n, q, x = 0;
    cin >> n >> q;
    while (q--) {
        uint b;
        cin >> b;
        uint bit = 1 << (b - 1);


        if (bit & n) continue;

        if (bit > n) x += (bit - n), n = bit;
        else {
            uint tmp = -1;
            tmp <<= (b - 1);
            tmp = ~tmp;
            tmp &= n;
            x += (bit - tmp), n += (bit - tmp);
        }
    }
    cout << x << endl;
    return 0;
}