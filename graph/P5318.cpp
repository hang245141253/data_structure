#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100005;
const int M = 1000005;

int m, n;
int Head[N], Edge[M], Next[M], cnt;
vector<int> E[M];
bool vis[N];
bool vis2[N];

void add_Edge(int u, int v) {
    Edge[cnt] = v;
    Next[cnt] = Head[u];
    Head[u] = cnt++;
}

void dfs(int u) {
    vis[u] = 1;
    printf("%d ", u);
    for (int i = Head[u]; i != -1; i = Next[i]) {
        int j = Edge[i];
        if (!vis[j]) dfs(j);
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    vis2[u] = 1;
    printf("%d ", u);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = Head[t]; i != -1; i = Next[i]) {
            int j = Edge[i];
            if (vis2[j] == 0) {
                vis2[j] = 1;
                printf("%d ", j);
                q.push(j);
            }
        }
    }
}

int main() {
    memset(Head, -1, sizeof(Head));
    cin >> n >> m;

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        E[u].push_back(v);

    }

    for (int i = 1; i <= n; i++) {
        sort(E[i].begin(), E[i].end(), greater<int>());
        for (auto x : E[i]) {
            add_Edge(i, x);
        }
        // for (int j = Head[i]; j != -1; j = Next[j]) {
        //     cout << i << " " << Edge[j] << endl;
        // }
    }

    dfs(1);
    printf("\n");
    bfs(1);

    return 0;
}