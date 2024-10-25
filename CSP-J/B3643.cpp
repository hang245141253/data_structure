#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1005;
const int MAX_M = 200005;

int G[MAX_N][MAX_N];
int Head[MAX_N], Edge[MAX_M], Next[MAX_M], cnt;

void add_Edge(int u, int v) {
    Edge[cnt] = v;
    Next[cnt] = Head[u];
    Head[u] = cnt++;
}

int main() {
    memset(Head, -1, sizeof(Head));
    int n, m;
    cin >> n >> m;

    int u, v;
    while (m--) {
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
        add_Edge(u, v);
        add_Edge(v, u);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", G[i][j]);
        } printf("\n");
    }

    for (int i = 1; i <= n; i++) {
        vector<int> output;
        for (int j = Head[i]; j != -1; j = Next[j]) {
            output.push_back(Edge[j]);
        }
        sort(output.begin(), output.end());
        printf("%ld ", output.size());
        for (auto x : output) {
            printf("%d ", x);
        } putchar('\n');
    }

    return 0;
}