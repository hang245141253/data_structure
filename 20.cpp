#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;  // 定义常量 N 表示最大节点数
int n, fa[N][20], FA[N], dep[N];  // n 是节点数，fa 是倍增数组，FA 是父节点数组，dep 是深度数组
vector<int> V[N];  // 邻接表表示的树

// 深度优先搜索函数，计算每个节点的深度
void dfs(int u) {
    dep[u] = dep[FA[u]] + 1;  // 当前节点深度为父节点深度加 1
    for (int i = 0; i < V[u].size(); i++) {  // 遍历当前节点的所有子节点
        int k = V[u][i];  // 获取子节点编号
        if (k == FA[u]) continue;  // 如果子节点是父节点，跳过
        FA[k] = u;  // 设置子节点的父节点为当前节点
        dfs(k);  // 递归遍历子节点
    }
}

// 初始化倍增数组 fa
void init() {
    for (int i = 1; i <= n; i++) fa[i][0] = FA[i];  // 初始化第一列为直接父节点
    for (int i = 1; i <= 18; i++)  // 计算 2^i 祖先
        for (int j = 1; j <= n; j++)
            fa[j][i] = fa[fa[j][i - 1]][i - 1];  // 使用动态规划计算
}

// 计算 x 和 y 的最近公共祖先
int LCA(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);  // 确保 x 更深
    for (int i = 18; i >= 0; i--)  // 将 x 提升到和 y 同样的深度
        if (dep[fa[x][i]] >= dep[y])  // ① 确保 x 的深度大于等于 y 的深度
            x = fa[x][i];
    if (x == y) return x;  // 如果提升后两个节点相同，返回 x
    for (int i = 18; i >= 0; i--)  // 同时提升 x 和 y 直到它们的父节点相同
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    if (dep[x] > dep[y]) swap(x, y);  // 确保 x 和 y 的深度关系
    return fa[x][0];  // ② 返回它们的公共父节点
}

// 检查 z 是否在 x 到 y 的路径上
bool check(int x, int y, int z) {
    return LCA(x, z) == z || LCA(y, z) == z;  // ③ 检查 z 是否为 x 或 y 的公共祖先之一
}

// 主函数
int main() {
    cin >> n;  // 输入节点数
    for (int i = 1; i < n; i++) {  // 输入树的边
        int x, y;
        cin >> x >> y;
        V[x].push_back(y);  // 将 y 加入 x 的邻接表
        V[y].push_back(x);  // 将 x 加入 y 的邻接表
    }

    dfs(1);  // 从根节点 1 开始进行深度优先搜索
    init();  // 初始化倍增数组

    int m;  // 查询次数
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;  // 输入查询的三个节点
        int lca = LCA(x, y);  // 计算 x 和 y 的最近公共祖先
        bool chk;
        if (lca == x || lca == y) {  // 如果 lca 是 x 或 y 中的一个
            if (dep[x] > dep[y]) swap(x, y);  // 确保 x 比 y 深
            chk = check(x, y, z);  // ④ 检查 z 是否在 x 到 y 的路径上
        } else {
            chk = check(x, lca, z) && check(y, lca, z);  // ⑤ 检查 z 是否在 x 到 y 的路径上
        }
        if (chk) puts("YES");  // 输出结果
        else puts("NO");
    }
    return 0;
}
