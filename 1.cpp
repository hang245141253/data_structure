#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int getHeight(TreeNode *root) {
        if (root == nullptr) return 0;
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        if (l < 0 || r < 0) return -1;
        if (abs(l - r) > 1) return -1;
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root) >= 0;
    }
};


int main() {
    int level;
    cin >> level;
    int bits = 1 << (level - 1);
    cout << bits << endl;
    return 0;
}