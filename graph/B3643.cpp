#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 1005

int n, m;
bool G1[MAX_N][MAX_N];
vector<int> G2[MAX_N];


void addEdge1(int u, int v) {
    G1[u][v] = G1[v][u] = 1;
}

void addEdge2(int u, int v) {
    G2[u].push_back(v);
    G2[v].push_back(u);
}

void print1() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << G1[i][j] << " ";
        } cout << endl;
    }
}

void print2() {
    for (int i = 1; i <= n; i++) {
        sort(G2[i].begin(), G2[i].end());
        cout << G2[i].size() << " ";
        for (int j = 0; j < G2[i].size(); j++) {
            cout << G2[i][j] << " ";
        } cout << endl;
    }
}


int main() {
    cin >> n >> m;
    
    int u, v;
    while (m--) {
        cin >> u >> v;
        addEdge1(u, v);
        addEdge2(u, v);
    }

    print1();
    print2();
    return 0;
}