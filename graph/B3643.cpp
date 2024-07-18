#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 1005;
const int MAX_M = 200005; // 假设边数不超过10^5，乘2因为无向图每条边存储两次

int G[MAX_N][MAX_N];
int Head[MAX_N], Edge[MAX_M], Next[MAX_M], cnt;


// 链式前向星，本质是静态链表
void add_Edge(int u, int v) {         
    Edge[cnt] = v;// 节点cnt的data域存值
    Next[cnt] = Head[u];// 节点cnt的指针域指向head[u]的指向
    Head[u] = cnt++;// head[u]指向cnt,完成头插，并且cnt++移动到空位
    // Head[u]和cnt都属于指针
}

// E[N]表示某个点的val
// NE[N]表示某个点的next指针
// 两个数组用下标关联

int main() {
    int n, m;
    cin >> n >> m;

    memset(Head, -1, sizeof(Head));

    int u, v;
    while (m--) {
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
        add_Edge(u, v);
        add_Edge(v, u); // 无向图模拟有向图添加双向边
    }

    // 打印邻接矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", G[i][j]);
        } putchar('\n');
    }

    // 打印邻接表
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

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cstring>

// using namespace std;

// const int MAXN = 1005; // 假设顶点数不超过1000
// const int MAXM = 200005; // 假设边数不超过10^5，乘2因为无向图每条边存储两次

// // head顶点集、edge边集、nextEdge每个节点的next指针
// int head[MAXN], edge[MAXM], nextEdge[MAXM];
// int cnt = 0; // 边的编号

// int adjMatrix[MAXN][MAXN]; // 邻接矩阵
// int degree[MAXN]; // 度数

// // 基本树图的题都是这么存的。（链表头插节点）
// void addEdge(int u, int v) {
//     edge[cnt] = v;             // 节点cnt的data域存值
//     nextEdge[cnt] = head[u];   // 节点cnt的指针域指向head[u]的指向
//     head[u] = cnt++;           // head[u]指向cnt,完成头插，并且cnt++移动到空位
//     // head[u]和cnt都属于指针
// }

// // E[N]表示某个点的val
// // NE[N]表示某个点的next指针
// // 两个数组用下标关联

// int main() {
//     int n, m;
//     cin >> n >> m;

//     memset(head, -1, sizeof(head));
//     memset(adjMatrix, 0, sizeof(adjMatrix));
//     memset(degree, 0, sizeof(degree));

//     for (int i = 0; i < m; ++i) {
//         int u, v;
//         cin >> u >> v;
//         adjMatrix[u][v] = 1;
//         adjMatrix[v][u] = 1;
//         addEdge(u, v);
//         addEdge(v, u);
//         degree[u]++;
//         degree[v]++;
//     }

//     // 输出邻接矩阵
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= n; ++j) {
//             cout << adjMatrix[i][j] << (j == n ? "\n" : " ");
//         }
//     }

//     // 输出邻接表
//     for (int i = 1; i <= n; ++i) {
//         vector<int> neighbors;
//         for (int j = head[i]; j != -1; j = nextEdge[j]) {
//             neighbors.push_back(edge[j]);
//         }
//         sort(neighbors.begin(), neighbors.end());
//         cout << degree[i];
//         for (int neighbor : neighbors) {
//             cout << " " << neighbor;
//         }
//         cout << "\n";
//     }

//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// #define MAX_N 1005

// int n, m;
// bool G1[MAX_N][MAX_N];
// vector<int> G2[MAX_N];


// void addEdge1(int u, int v) {
//     G1[u][v] = G1[v][u] = 1;
// }

// void addEdge2(int u, int v) {
//     G2[u].push_back(v);
//     G2[v].push_back(u);
// }

// void print1() {
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             cout << G1[i][j] << " ";
//         } cout << endl;
//     }
// }

// void print2() {
//     for (int i = 1; i <= n; i++) {
//         sort(G2[i].begin(), G2[i].end());
//         cout << G2[i].size() << " ";
//         for (int j = 0; j < G2[i].size(); j++) {
//             cout << G2[i][j] << " ";
//         } cout << endl;
//     }
// }


// int main() {
//     cin >> n >> m;
    
//     int u, v;
//     while (m--) {
//         cin >> u >> v;
//         addEdge1(u, v);
//         addEdge2(u, v);
//     }

//     print1();
//     print2();
//     return 0;
// }