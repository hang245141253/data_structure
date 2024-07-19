/* 模板
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100005, MAX_M = MAX_N * 2;

int Head[MAX_N], Edge[MAX_M], Next[MAX_M], cnt;

void add_Edge(int u, int v) {
    Edge[cnt] = v;
    Next[cnt] = Head[u];
    Head[u] = cnt++;
}

int main() {
    memset(Head, -1, sizeof(Head));
    
    return 0;
}

*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 100005; 

int n, m;
int Head[MAX], Edge[MAX], Next[MAX], cnt;
int vis[MAX];
/*
根据BFS,第一次遍历到就是最短距离

queue 把1先入队

while (！queue) {
    int t = 队头
    遍历所有t的临近点x {
        if (x未遍历) {
            x入queue
            vis[x] = vis[t] + 1;
            // vis记录距离&标记是否被遍历
        }
    }
}

*/

// 链式前向星添加边
void add_edge(int u, int v) {
    Edge[cnt] = v;
    Next[cnt] = Head[u];
    Head[u] = cnt++;
}

int bfs() {
    queue<int> q;
    q.push(1);
    memset(vis, -1, sizeof(vis));
    vis[1] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop(); 
        for (int i = Head[t]; i != -1; i = Next[i]) {
            int j = Edge[i];
            if (vis[j] == -1) {
                vis[j] = vis[t] + 1;
                q.push(j);
            }
        }
    }
    return vis[n];
}

int main() {
    cin  >> n >> m;
    memset(Head, -1, sizeof(Head));
    int a, b;
    while (m--) {
        cin >> a >> b;
        add_edge(a, b);
    }
    cout << bfs() << endl;
    return 0;
}