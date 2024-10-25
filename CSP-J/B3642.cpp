#include <iostream>
#include <queue>
#include <list>

using namespace std;

const int MAXN = 1000005;

int leftChild[MAXN], rightChild[MAXN];
int preorder[MAXN], inorder[MAXN], postorder[MAXN], levelorder[MAXN];
int preIndex = 0, inIndex = 0, postIndex = 0, levelIndex = 0;

// dfs(x) 以x结点作为子树 进行  左 右
void dfs(int node) {
    if (node == 0) return;
    // preorder[preIndex++] = node;  
    

    dfs(leftChild[node]); // 左
    // inorder[inIndex++] = node;


    dfs(rightChild[node]); // 右
    // postorder[postIndex++] = node; // cout << node << endl; // 根
}

void bfs(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == 0) continue;
        levelorder[levelIndex++] = node;
        if (leftChild[node] != 0) q.push(leftChild[node]);
        if (rightChild[node] != 0) q.push(rightChild[node]);
    }
}

int main() {
    ios::sync_with_stdio(false); // 解除C++标准流和C标准流的同步
    cin.tie(0); // 解除cin和cout之间的绑定关系

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        leftChild[i] = l;
        rightChild[i] = r;
    }
    
    dfs(1);
    bfs(1);
    
    for (int i = 0; i < preIndex; ++i) {
        cout << preorder[i] << (i == preIndex - 1 ? '\n' : ' ');
    }
    
    for (int i = 0; i < inIndex; ++i) {
        cout << inorder[i] << (i == inIndex - 1 ? '\n' : ' ');
    }
    
    for (int i = 0; i < postIndex; ++i) {
        cout << postorder[i] << (i == postIndex - 1 ? '\n' : ' ');
    }

    // for (int i = 0; i < levelIndex; ++i) {
    //     cout << levelorder[i] << (i == levelIndex - 1 ? '\n' : ' ');
    // }

    return 0;
}
