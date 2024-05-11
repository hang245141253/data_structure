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
    void getResult(TreeNode* root, int k, vector<vector<int>> &ans) {
        if (root == nullptr) return;
        if (k == ans.size()) ans.push_back(vector<int>());
        ans[k].push_back(root->val);
        getResult(root->left, k + 1, ans);
        getResult(root->right, k + 1, ans);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        getResult(root, 0, ans);
        for (int i = 1; i < ans.size(); i += 2) {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};

int main() {}