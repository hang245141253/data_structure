#include <iostream>
using namespace std;

const int N = 500005;

int Head[N], Edge[N], Next[N], cnt;

void add_Edge(int u, int v) {
    Edge[cnt] = v;
    Next[cnt] = Head[u];
    Head[u] = cnt++;
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0, x, y; i < n - 1; i++) {
        add_Edge(x, y);
        add_Edge(y, x); // 添加无向边
    }

    

    return 0;
}