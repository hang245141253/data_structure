#include <algorithm>
#include <iostream>

using namespace std;
const int N = 1e6 + 5;
// 默认head是 0，tail是 -1
// 起始 a[0] = 1, a[1] = -1, 代表  0 -> [1|-1] -> -1
int a[N] = {1, -1};

void insert(int x, int y) {
    a[y] = a[x];
    a[x] = y;
}

void find(int x) {
    if (a[x] == -1)
        cout << 0 << endl;
    else
        cout << a[x] << endl;
}

void remove(int x) {
    a[x] = a[a[x]];
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int k, x, y;
        cin >> k;
        if (k == 1) {
            cin >> x >> y;
            insert(x, y);
        } else if (k == 2) {
            cin >> x;
            find(x);
        } else if (k == 3) {
            cin >> x;
            remove(x);
        }
    }
    /*
    for(int i = 0; a[i] != -1 ; i = a[i]) {
        cout << a[i] << " ";
    }
    */
    return 0;
}
/*
1 99  -1
0 1   99

1 99
1 99 50
1 99 75 50
75
1 99 50
99
*/