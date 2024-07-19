#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100005, MAX_M = MAX_N * 2;

int n, ans = MAX_N;
int Head[MAX_N], Edge[MAX_M], Next[MAX_M], cnt;
bool vis[MAX_N];

void add_edge(int u, int v) {
    Edge[cnt] = v;
    Next[cnt] = Head[u];
    Head[u] = cnt++;
}
/*DFS模板
void dfs(int u) {
    vis[u] = 1;
    for (int i = Head[u]; i != -1; i = Head[i]) {
        int j = Edge[i];
        if (!vis[j]) dfs(j);
    }
} 

树的重心：
枚举去掉每个节点，其各个连通块的最大连通的数目，
找到最大连通块最小值，就是树的重心

快速找到这个值，可采取DFS的方式：
因为DFS可以算出每一个子树的大小。
总节点数 - (左子树个数+右子树个数+1(自身))就是剩余
父节点组成的最大连通块的节点数

定义dfs的语义信息是以u为根的子树中 点的数量：
(各个子树数量和+1(自身)）
*/

int dfs(int u) {
    vis[u] = 1;
    int u_sum = 1; // 以u为根节点的子树 点的数量，初始化为1是把本身先加上
    int u_max = 0; // 存去掉节点u后，形成的几个最大连通块中，节点最多连通块的节点数

    for (int i = Head[u]; i != -1; i = Next[i]) {
        int j = Edge[i];
        if (!vis[j]) {
            int ztree = dfs(j); // ztree存储以j为根节点的子树 点的数量
            u_max = max(u_max, ztree);
            u_sum += ztree;
        }
    }
    u_max = max(u_max, n - u_sum);
    ans = min(u_max, ans);

    return u_sum;
} 

int main() {
    memset(Head, -1, sizeof(Head));
    cin >> n;
    for (int i = 0; i < n - 1; i++) { // n个节点是树肯定有n-1条边
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
        add_edge(b, a);
    }

    dfs(1);
    cout << ans << endl;

    return 0;
}