#include <iostream>
#include <queue>
#include <vector>
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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode *> que;
        que.push(root);
        int k = 0;
        while (!que.empty()) {
            ans.push_back(vector<int>());
            for (int i = que.size(); i > 0; i--) {
                TreeNode *tmp = que.front();
                que.pop();
                if (tmp->left)    que.push(tmp->left);
                if (tmp->right)   que.push(tmp->right);
                ans[k].push_back(tmp->val);
            }
            k++;
        }

        for (int i = 0, j = ans.size() - 1; i < j; i++, j--) {
            swap(ans[i], ans[j]);
        }

        return ans;
    }
};

int main() {}